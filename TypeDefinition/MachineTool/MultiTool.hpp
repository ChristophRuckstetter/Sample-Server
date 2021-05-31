#pragma once
#include "../../UmatiServerLib/BindableMemberPlaceholder.hpp"
#include "../TypeDefinition.hpp"
#include "Constants.hpp"
#include "Tool.hpp"
#include "ToolLife.hpp"

namespace machineTool {

struct MultiTool_t : public BaseTool_t {
  BindableMemberPlaceholder<BindableMember, Tool_t> Tool;
};

struct MultiTool_ToolLife_t {
  BindableMemberPlaceholder<BindableMember, std::variant<ToolLife_t<std::int32_t>, ToolLife_t<double>>> ToolLifeEntry;
};

}  // namespace machineTool

REFL_TYPE(
  machineTool::MultiTool_t,
  Bases<machineTool::BaseTool_t>(),
  UmatiServerLib::attribute::UaObjectType(UmatiServerLib::constexp::NodeId(constants::NsMachineToolUri, UA_MACHINETOOLID_MULTITOOLTYPE)))
REFL_TYPE(
  machineTool::MultiTool_ToolLife_t,
  UmatiServerLib::attribute::UaObjectType(  // TOOD handle correctly when this is pointing to an object instead of an object type
    UmatiServerLib::constexp::NodeId(constants::Ns0Uri, UA_NS0ID_BASEOBJECTTYPE)))
REFL_FIELD(
  ToolLifeEntry,
  UmatiServerLib::attribute::PlaceholderOptional(),
  UmatiServerLib::attribute::MemberInTypeNodeId(
    UmatiServerLib::constexp::NodeId(constants::NsMachineToolUri, UA_MACHINETOOLID_MULTITOOLTYPE_TOOLLIFE_TOOLLIFEENTRY)))
REFL_FIELD(
  Tool,
  UmatiServerLib::attribute::PlaceholderOptional(),
  UmatiServerLib::attribute::MemberInTypeNodeId(UmatiServerLib::constexp::NodeId(constants::NsMachineToolUri, UA_MACHINETOOLID_MULTITOOLTYPE_TOOL)))

REFL_END
