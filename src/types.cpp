#include "duckdb_extension.h"
#include "types.hpp"

#include <vector>
#include <string>

DUCKDB_EXTENSION_EXTERN

static constexpr auto INET_TYPE_NAME = "INET";

static void RegisterInetType(duckdb_connection connection){
    // Create the type
    std::vector<duckdb_logical_type> types;
    types.push_back(duckdb_create_logical_type(DUCKDB_TYPE_UTINYINT));
    types.push_back(duckdb_create_logical_type(DUCKDB_TYPE_HUGEINT));
    types.push_back(duckdb_create_logical_type(DUCKDB_TYPE_USMALLINT));

    std::vector<const char *> names;
    names.push_back("ip_type");
    names.push_back("address");
    names.push_back("mask");

    auto logical_type = duckdb_create_struct_type(types.data(), names.data(), types.size());
    duckdb_logical_type_set_alias(logical_type, INET_TYPE_NAME);

    // Register the type
    auto status = duckdb_register_logical_type(connection, logical_type, nullptr);
    if(status != duckdb_state::DuckDBSuccess) {
        // TODO: error handling?
        throw std::runtime_error("Failed to register type");
    }

    // Clean up
    for (idx_t i = 0; i < types.size(); i++) {
        duckdb_destroy_logical_type(&types[i]);
    }
    duckdb_destroy_logical_type(&logical_type);
}

void RegisterTypes(duckdb_connection connection) {
    RegisterInetType(connection);
}