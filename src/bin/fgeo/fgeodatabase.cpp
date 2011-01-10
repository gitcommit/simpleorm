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

    _siPrefixes = _core->createTable("si_prefixes");
    _siPrefixes->createTableColumn("id", _int, true)->createDefault(_core->createSequence("seq_si_prefixes"));
    _siPrefixes->createTableColumn("name", _text, "New SI Prefix");
    _siPrefixes->createTableColumn("code", _code, _null);
    _siPrefixes->createTableColumn("symbol", _text);
    _siPrefixes->createTableColumn("factor", _numeric, 1.0);
    _siPrefixes->createTableColumn("description", _text, "");
    _siPrefixes->createUniqueConstraint("u_si_prefixes_name")->add("name");
    _siPrefixes->createUniqueConstraint("u_si_prefixes_factor")->add("factor");
    _siPrefixes->createUniqueConstraint("u_si_prefixes_symbol")->add("symbol");
    _siPrefixes->createUniqueConstraint("u_si_prefixes_code")->add("code");
    _siPrefixes->createPrimaryKeyConstraint("pk_si_prefixes")->add("id");
    _siPrefixes->column("name")->createCheckConstraint("!= ''", "chk_si_prefixes_name_not_empty");
    
    _units = _core->createTable("units");
    _units->createTableColumn("id", _int, true)->createDefault(_core->createSequence("seq_units"));
    _units->createTableColumn("si_prefix_id", _siPrefixes->column("id"), "fk_units_si_prefix_exists", false);
    _units->createTableColumn("name", _text, "New Unit");
    _units->createTableColumn("code", _code, _null);
    _units->createTableColumn("symbol", _text);
    _units->createTableColumn("base_unit_id", _units->column("id"), "fk_units_base_unit_exists", false);
    _units->createTableColumn("description", _text, "");
    _units->createPrimaryKeyConstraint("pk_units")->add("id");
    _units->createUniqueConstraint("u_units_name")->add("name");
    _units->createUniqueConstraint("u_units_symbol")->add("symbol");
    _units->createUniqueConstraint("u_units_code")->add("code");
    
    _unitConversions = _core->createTable("unit_conversions");
    _unitConversions->createTableColumn("id", _int, true)->createDefault(_core->createSequence("seq_unit_conversions"));
    _unitConversions->createTableColumn("source_unit_id", _siPrefixes->column("id"), "fk_unit_conversions_source_exists", true);
    _unitConversions->createTableColumn("target_unit_id", _siPrefixes->column("id"), "fk_unit_conversions_target_exists", true);
    _unitConversions->createTableColumn("factor", _numeric, 1.0);
    _unitConversions->createTableColumn("description", _text, "");
    _unitConversions->createPrimaryKeyConstraint("pk_unit_conversions")->add("id");
    _unitConversions->createUniqueConstraint("u_unit_conversions")->add("source_unit_id");
    _unitConversions->uniqueConstraint("u_unit_conversions")->add("target_unit_id");
}

FGeoDatabase::FGeoDatabase(const FGeoDatabase& orig)
: Database(orig) {
}

FGeoDatabase::~FGeoDatabase() {
}

