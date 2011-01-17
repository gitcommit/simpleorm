#include <orm/insertvisitor.hpp>

#include <sstream>
#include <boost/assert.hpp>

#include <orm/entity.hpp>
#include <dbconn/insertquery.hpp>

#include <orm/mapping.hpp>
#include <dbmodel/table.hpp>

InsertVisitor::InsertVisitor()
: PersistanceVisitor() {
}

InsertVisitor::InsertVisitor(const InsertVisitor& o)
: PersistanceVisitor(o) {
}

InsertVisitor::~InsertVisitor() {
}

void InsertVisitor::perform(Entity* e) {
    BOOST_ASSERT(0 != e);
    BOOST_ASSERT(e->hasMapping());
    Mapping* m = e->mapping();
    BOOST_ASSERT(0 != m);
    BOOST_ASSERT(m->hasTable());

    setQuery(new InsertQuery(e->session()));

    StringStream ss;
    StringStream colNames;
    StringStream placeholders;

    TableColumnMap columns = e->mapping()->table()->columns();

    for (TableColumnMapConstIterator i = columns.begin(); i != columns.end(); ++i) {
        if (columns.begin() != i) {
            colNames << ", ";
            placeholders << ", ";
        }
        colNames << i->second->name();
        placeholders << ":" << i->second->name();
    }
    ss << "INSERT INTO " << e->mapping()->table()->qualifiedName()
            << "(" << colNames.str() << ") VALUES (" << placeholders.str() << ")";
    query()->setSql(ss.str());
}