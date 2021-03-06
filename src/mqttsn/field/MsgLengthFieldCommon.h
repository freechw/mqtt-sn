// Generated by commsdsl2comms v3.4.0

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref mqttsn::field::MsgLengthField field.

#pragma once

#include <cstdint>

namespace mqttsn
{

namespace field
{

/// @brief Scope for all the common definitions of the member fields of
///     @ref mqttsn::field::MsgLengthField field.
struct MsgLengthFieldMembersCommon
{
    /// @brief Common types and functions for
    ///     @ref mqttsn::field::MsgLengthFieldMembers::Short field.
    struct ShortCommon
    {
        /// @brief Re-definition of the value type used by
        ///     mqttsn::field::MsgLengthFieldMembers::Short field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref mqttsn::field::MsgLengthFieldMembers::Short field.
        static const char* name()
        {
            return "short";
        }
        
    };
    
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref mqttsn::field::MsgLengthFieldMembers::Long field.
    struct LongMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref mqttsn::field::MsgLengthFieldMembers::LongMembers::Long field.
        struct LongCommon
        {
            /// @brief Re-definition of the value type used by
            ///     mqttsn::field::MsgLengthFieldMembers::LongMembers::Long field.
            using ValueType = std::uint16_t;
        
            /// @brief Name of the @ref mqttsn::field::MsgLengthFieldMembers::LongMembers::Long field.
            static const char* name()
            {
                return "long";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref mqttsn::field::MsgLengthFieldMembers::Long field.
    struct LongCommon
    {
        /// @brief Name of the @ref mqttsn::field::MsgLengthFieldMembers::Long field.
        static const char* name()
        {
            return "long";
        }
        
    };
    
    
};

/// @brief Scope for all the common definitions of the
///     @ref mqttsn::field::MsgLengthField field.
struct MsgLengthFieldCommon
{
    /// @brief Name of the @ref mqttsn::field::MsgLengthField field.
    static const char* name()
    {
        return "Length";
    }
    
};


} // namespace field

} // namespace mqttsn


