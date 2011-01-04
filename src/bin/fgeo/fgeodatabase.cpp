#include <fgeodatabase.hpp>

FGeoDatabase::FGeoDatabase(const std::string& name)
: Database(name) {
    _int = createDataType("int", "INTEGER");
    _numeric = createDataType("double", "NUMERIC");
    _text = createDataType("text", "TEXT");
    _timestamp = createDataType("timestamp", "TIMESTAMP");
    _date = createDataType("date", "DATE");
    _code = _text;
    _none = createDataType("none", "NULL");
    
    _currentUser = createDatabaseConstant("CURRENT_USER", _text);
    _currentTimestamp = createDatabaseConstant("CURRENT_TIMESTAMP", _timestamp);
    _null = createDatabaseConstant("NULL", _none);

    _core = createSchema("core");
    _geology = createSchema("geology");
    _palaeontology = createSchema("palaeontology");
    _chemistry = createSchema("chemistry");

    _core->createSequence("seq_units");
    _core->createSequence("seq_unit_conversions");

    _siPrefixes = _core->createTable("si_prefixes");
    _siPrefixes->createTableColumn("id", _int, true)->createDefault(_core->createSequence("seq_si_prefixes"));
    _siPrefixes->createTableColumn("name", _text, "New SI Prefix");
    _siPrefixes->createTableColumn("core", _code, _null);
    _siPrefixes->createTableColumn("symbol", _text);
    _siPrefixes->createTableColumn("factor", _numeric, 1.0);
    _siPrefixes->createTableColumn("description", _text, "");
    _siPrefixes->createUniqueConstraint("u_si_prefixes_name")->add("name");
    _siPrefixes->createUniqueConstraint("u_si_prefixes_factor")->add("factor");
    _siPrefixes->createUniqueConstraint("u_si_prefixes_symbol")->add("symbol");
    _siPrefixes->createPrimaryKeyConstraint("pk_si_prefixes")->add("id");
    
    _units = _core->createTable("units");
    _unitConversions = _core->createTable("unit_convesions");
}

FGeoDatabase::FGeoDatabase(const FGeoDatabase& orig)
: Database(orig) {
}

FGeoDatabase::~FGeoDatabase() {
}

