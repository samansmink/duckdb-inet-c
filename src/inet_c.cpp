#include "duckdb_extension.h"

// TODO add all this shit

//   // add the casts to and from INET type
//   ExtensionUtil::RegisterCastFunction(*db.instance, LogicalType::VARCHAR,
//                                       inet_type,
//                                       INetFunctions::CastVarcharToINET);
//   ExtensionUtil::RegisterCastFunction(*db.instance, inet_type,
//                                       LogicalType::VARCHAR,
//                                       INetFunctions::CastINETToVarchar);
//
//   // add inet functions
//   ExtensionUtil::RegisterFunction(
//       *db.instance, ScalarFunction("host", {inet_type}, LogicalType::VARCHAR,
//                                    INetFunctions::Host));
//   ExtensionUtil::RegisterFunction(
//       *db.instance, ScalarFunction("family", {inet_type}, LogicalType::UTINYINT,
//                                    INetFunctions::Family));
//   ExtensionUtil::RegisterFunction(
//       *db.instance, ScalarFunction("netmask", {inet_type}, {inet_type},
//                                    INetFunctions::Netmask));
//   ExtensionUtil::RegisterFunction(
//       *db.instance, ScalarFunction("network", {inet_type}, {inet_type},
//                                    INetFunctions::Network));
//   ExtensionUtil::RegisterFunction(
//       *db.instance, ScalarFunction("broadcast", {inet_type}, {inet_type},
//                                    INetFunctions::Broadcast));
//   ExtensionUtil::RegisterFunction(*db.instance, GetEscapeFunctionSet());
//   ExtensionUtil::RegisterFunction(*db.instance, GetUnescapeFunction());
//
//   // Add - function with ALTER_ON_CONFLICT
//   ScalarFunction substract_fun("-", {inet_type, LogicalType::HUGEINT},
//                                inet_type, INetFunctions::Subtract);
//   ExtensionUtil::AddFunctionOverload(*db.instance, substract_fun);
//
//   ScalarFunction add_fun("+", {inet_type, LogicalType::HUGEINT}, inet_type,
//                          INetFunctions::Add);
//   ExtensionUtil::AddFunctionOverload(*db.instance, add_fun);
//
//   // Add IP range operators
//   ExtensionUtil::RegisterFunction(*db.instance,
//                                   ScalarFunction("<<=", {inet_type, inet_type},
//                                                  LogicalType::BOOLEAN,
//                                                  INetFunctions::ContainsLeft));
//   ExtensionUtil::RegisterFunction(*db.instance,
//                                   ScalarFunction(">>=", {inet_type, inet_type},
//                                                  LogicalType::BOOLEAN,
//                                                  INetFunctions::ContainsRight));
// }

#include <vector>
#include <string>
#include <types.hpp>

DUCKDB_EXTENSION_ENTRYPOINT(duckdb_connection connection, duckdb_extension_info info, struct duckdb_extension_access *access) {

	RegisterTypes(connection);

	// Return true to indicate succesful initialization
	return true;
}


