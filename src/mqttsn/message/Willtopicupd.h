// Generated by commsdsl2comms v3.4.0

/// @file
/// @brief Contains definition of <b>"WILLTOPICUPD"</b> message and its fields.

#pragma once

#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/Optional.h"
#include "comms/options.h"
#include "mqttsn/MsgId.h"
#include "mqttsn/field/FieldBase.h"
#include "mqttsn/field/Flags.h"
#include "mqttsn/field/WillTopic.h"
#include "mqttsn/message/WilltopicupdCommon.h"
#include "mqttsn/options/DefaultOptions.h"

namespace mqttsn
{

namespace message
{

/// @brief Fields of @ref Willtopicupd.
/// @tparam TOpt Extra options
/// @see @ref Willtopicupd
/// @headerfile "mqttsn/message/Willtopicupd.h"
template <typename TOpt = mqttsn::options::DefaultOptions>
struct WilltopicupdFields
{
    /// @brief Scope for all the member fields of
    ///     @ref Flags optional.
    struct FlagsMembers
    {
        /// @brief Definition of <b>"FlagsField"</b> field.
        struct FlagsField : public
            mqttsn::field::Flags<
                TOpt
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return mqttsn::message::WilltopicupdFieldsCommon::FlagsMembersCommon::FlagsFieldCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"Flags"</b> field.
    struct Flags : public
        comms::field::Optional<
            typename FlagsMembers::FlagsField
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return mqttsn::message::WilltopicupdFieldsCommon::FlagsCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"WillTopic"</b> field.
    using WillTopic =
        mqttsn::field::WillTopic<
            TOpt
        >;
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Flags,
        WillTopic
    >;
};

/// @brief Definition of <b>"WILLTOPICUPD"</b> message class.
/// @details
///     See @ref WilltopicupdFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "mqttsn/message/Willtopicupd.h"
template <typename TMsgBase, typename TOpt = mqttsn::options::DefaultOptions>
class Willtopicupd : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Willtopicupd,
        comms::option::def::StaticNumIdImpl<mqttsn::MsgId_Willtopicupd>,
        comms::option::def::FieldsImpl<typename WilltopicupdFields<TOpt>::All>,
        comms::option::def::MsgType<Willtopicupd<TMsgBase, TOpt> >,
        comms::option::def::HasName,
        comms::option::def::HasCustomRefresh
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Willtopicupd,
            comms::option::def::StaticNumIdImpl<mqttsn::MsgId_Willtopicupd>,
            comms::option::def::FieldsImpl<typename WilltopicupdFields<TOpt>::All>,
            comms::option::def::MsgType<Willtopicupd<TMsgBase, TOpt> >,
            comms::option::def::HasName,
            comms::option::def::HasCustomRefresh
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_flags type and @b field_flags() access fuction
    ///         for @ref WilltopicupdFields::Flags field.
    ///     @li @b Field_willTopic type and @b field_willTopic() access fuction
    ///         for @ref WilltopicupdFields::WillTopic field.
    COMMS_MSG_FIELDS_NAMES(
        flags,
        willTopic
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static_assert(MsgMinLen == 0U, "Unexpected min serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return mqttsn::message::WilltopicupdCommon::name();
    }
    
    /// @brief Custom read functionality
    template <typename TIter>
    comms::ErrorStatus doRead(TIter& iter, std::size_t len)
    {
        auto es = Base::doRead(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }
            
        bool hasMissingFlags = field_flags().isMissing();
        bool hasEmptyTopic = field_willTopic().value().empty();
        if (hasMissingFlags != hasEmptyTopic) {
            return comms::ErrorStatus::InvalidMsgData;
        }
        
        return comms::ErrorStatus::Success;
    }
    
    /// @brief Custom refresh functionality
    bool doRefresh()
    {
        bool updated = Base::doRefresh();
        
        bool hasEmptyTopic = field_willTopic().value().empty();
        if ((hasEmptyTopic && field_flags().isMissing()) ||
            ((!hasEmptyTopic) && field_flags().doesExist())) {
            return updated;
        }
        
        if (hasEmptyTopic) {
            field_flags().setMissing();
            return true;
        }
        
        field_flags().setExists();
        return true;
    }
    
    
};

} // namespace message

} // namespace mqttsn

