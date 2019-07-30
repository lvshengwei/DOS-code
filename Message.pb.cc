// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Message.proto

#include "Message.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace Message {
namespace protobuf {
class MsgDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Msg>
      _instance;
} _Msg_default_instance_;
}  // namespace protobuf
}  // namespace Message
namespace protobuf_Message_2eproto {
static void InitDefaultsMsg() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::Message::protobuf::_Msg_default_instance_;
    new (ptr) ::Message::protobuf::Msg();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Message::protobuf::Msg::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Msg =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsMsg}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Msg.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, role_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, msgcategory_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, ip_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, port_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, int32op1_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, int32op2_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, int64op1_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, int64op2_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, dbop1_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, dbop2_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, operation_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, int32result_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, int64result_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Message::protobuf::Msg, dbresult_),
  3,
  4,
  0,
  1,
  5,
  6,
  7,
  8,
  9,
  10,
  2,
  13,
  11,
  12,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 19, sizeof(::Message::protobuf::Msg)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::Message::protobuf::_Msg_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "Message.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\rMessage.proto\022\020Message.protobuf\"\367\001\n\003Ms"
      "g\022\014\n\004role\030\001 \002(\005\022\023\n\013msgCategory\030\002 \002(\005\022\n\n\002"
      "ip\030\003 \001(\t\022\014\n\004port\030\004 \001(\t\022\020\n\010int32op1\030\005 \001(\005"
      "\022\020\n\010int32op2\030\006 \001(\005\022\020\n\010int64op1\030\007 \001(\003\022\020\n\010"
      "int64op2\030\010 \001(\003\022\r\n\005dbop1\030\t \001(\001\022\r\n\005dbop2\030\n"
      " \001(\001\022\021\n\toperation\030\013 \001(\t\022\023\n\013int32result\030\014"
      " \001(\005\022\023\n\013int64result\030\r \001(\003\022\020\n\010dbresult\030\016 "
      "\001(\001"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 283);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Message.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_Message_2eproto
namespace Message {
namespace protobuf {

// ===================================================================

void Msg::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Msg::kRoleFieldNumber;
const int Msg::kMsgCategoryFieldNumber;
const int Msg::kIpFieldNumber;
const int Msg::kPortFieldNumber;
const int Msg::kInt32Op1FieldNumber;
const int Msg::kInt32Op2FieldNumber;
const int Msg::kInt64Op1FieldNumber;
const int Msg::kInt64Op2FieldNumber;
const int Msg::kDbop1FieldNumber;
const int Msg::kDbop2FieldNumber;
const int Msg::kOperationFieldNumber;
const int Msg::kInt32ResultFieldNumber;
const int Msg::kInt64ResultFieldNumber;
const int Msg::kDbresultFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Msg::Msg()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_Message_2eproto::scc_info_Msg.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:Message.protobuf.Msg)
}
Msg::Msg(const Msg& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ip_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_ip()) {
    ip_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.ip_);
  }
  port_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_port()) {
    port_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.port_);
  }
  operation_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_operation()) {
    operation_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.operation_);
  }
  ::memcpy(&role_, &from.role_,
    static_cast<size_t>(reinterpret_cast<char*>(&int32result_) -
    reinterpret_cast<char*>(&role_)) + sizeof(int32result_));
  // @@protoc_insertion_point(copy_constructor:Message.protobuf.Msg)
}

void Msg::SharedCtor() {
  ip_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  port_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  operation_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&role_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&int32result_) -
      reinterpret_cast<char*>(&role_)) + sizeof(int32result_));
}

Msg::~Msg() {
  // @@protoc_insertion_point(destructor:Message.protobuf.Msg)
  SharedDtor();
}

void Msg::SharedDtor() {
  ip_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  port_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  operation_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Msg::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Msg::descriptor() {
  ::protobuf_Message_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Message_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Msg& Msg::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_Message_2eproto::scc_info_Msg.base);
  return *internal_default_instance();
}


void Msg::Clear() {
// @@protoc_insertion_point(message_clear_start:Message.protobuf.Msg)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 7u) {
    if (cached_has_bits & 0x00000001u) {
      ip_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      port_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000004u) {
      operation_.ClearNonDefaultToEmptyNoArena();
    }
  }
  if (cached_has_bits & 248u) {
    ::memset(&role_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&int64op1_) -
        reinterpret_cast<char*>(&role_)) + sizeof(int64op1_));
  }
  if (cached_has_bits & 16128u) {
    ::memset(&int64op2_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&int32result_) -
        reinterpret_cast<char*>(&int64op2_)) + sizeof(int32result_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool Msg::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Message.protobuf.Msg)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 role = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_role();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &role_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required int32 msgCategory = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          set_has_msgcategory();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &msgcategory_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string ip = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_ip()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->ip().data(), static_cast<int>(this->ip().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "Message.protobuf.Msg.ip");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string port = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_port()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->port().data(), static_cast<int>(this->port().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "Message.protobuf.Msg.port");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 int32op1 = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {
          set_has_int32op1();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &int32op1_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 int32op2 = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {
          set_has_int32op2();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &int32op2_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int64 int64op1 = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(56u /* 56 & 0xFF */)) {
          set_has_int64op1();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &int64op1_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int64 int64op2 = 8;
      case 8: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(64u /* 64 & 0xFF */)) {
          set_has_int64op2();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &int64op2_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional double dbop1 = 9;
      case 9: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(73u /* 73 & 0xFF */)) {
          set_has_dbop1();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &dbop1_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional double dbop2 = 10;
      case 10: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(81u /* 81 & 0xFF */)) {
          set_has_dbop2();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &dbop2_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string operation = 11;
      case 11: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(90u /* 90 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_operation()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->operation().data(), static_cast<int>(this->operation().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "Message.protobuf.Msg.operation");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 int32result = 12;
      case 12: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(96u /* 96 & 0xFF */)) {
          set_has_int32result();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &int32result_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int64 int64result = 13;
      case 13: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(104u /* 104 & 0xFF */)) {
          set_has_int64result();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &int64result_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional double dbresult = 14;
      case 14: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(113u /* 113 & 0xFF */)) {
          set_has_dbresult();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &dbresult_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Message.protobuf.Msg)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Message.protobuf.Msg)
  return false;
#undef DO_
}

void Msg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Message.protobuf.Msg)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 role = 1;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->role(), output);
  }

  // required int32 msgCategory = 2;
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->msgcategory(), output);
  }

  // optional string ip = 3;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->ip().data(), static_cast<int>(this->ip().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Message.protobuf.Msg.ip");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->ip(), output);
  }

  // optional string port = 4;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->port().data(), static_cast<int>(this->port().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Message.protobuf.Msg.port");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->port(), output);
  }

  // optional int32 int32op1 = 5;
  if (cached_has_bits & 0x00000020u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->int32op1(), output);
  }

  // optional int32 int32op2 = 6;
  if (cached_has_bits & 0x00000040u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->int32op2(), output);
  }

  // optional int64 int64op1 = 7;
  if (cached_has_bits & 0x00000080u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(7, this->int64op1(), output);
  }

  // optional int64 int64op2 = 8;
  if (cached_has_bits & 0x00000100u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(8, this->int64op2(), output);
  }

  // optional double dbop1 = 9;
  if (cached_has_bits & 0x00000200u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(9, this->dbop1(), output);
  }

  // optional double dbop2 = 10;
  if (cached_has_bits & 0x00000400u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(10, this->dbop2(), output);
  }

  // optional string operation = 11;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->operation().data(), static_cast<int>(this->operation().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Message.protobuf.Msg.operation");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      11, this->operation(), output);
  }

  // optional int32 int32result = 12;
  if (cached_has_bits & 0x00002000u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(12, this->int32result(), output);
  }

  // optional int64 int64result = 13;
  if (cached_has_bits & 0x00000800u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(13, this->int64result(), output);
  }

  // optional double dbresult = 14;
  if (cached_has_bits & 0x00001000u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(14, this->dbresult(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Message.protobuf.Msg)
}

::google::protobuf::uint8* Msg::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Message.protobuf.Msg)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 role = 1;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->role(), target);
  }

  // required int32 msgCategory = 2;
  if (cached_has_bits & 0x00000010u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->msgcategory(), target);
  }

  // optional string ip = 3;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->ip().data(), static_cast<int>(this->ip().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Message.protobuf.Msg.ip");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->ip(), target);
  }

  // optional string port = 4;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->port().data(), static_cast<int>(this->port().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Message.protobuf.Msg.port");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->port(), target);
  }

  // optional int32 int32op1 = 5;
  if (cached_has_bits & 0x00000020u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->int32op1(), target);
  }

  // optional int32 int32op2 = 6;
  if (cached_has_bits & 0x00000040u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, this->int32op2(), target);
  }

  // optional int64 int64op1 = 7;
  if (cached_has_bits & 0x00000080u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(7, this->int64op1(), target);
  }

  // optional int64 int64op2 = 8;
  if (cached_has_bits & 0x00000100u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(8, this->int64op2(), target);
  }

  // optional double dbop1 = 9;
  if (cached_has_bits & 0x00000200u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(9, this->dbop1(), target);
  }

  // optional double dbop2 = 10;
  if (cached_has_bits & 0x00000400u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(10, this->dbop2(), target);
  }

  // optional string operation = 11;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->operation().data(), static_cast<int>(this->operation().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Message.protobuf.Msg.operation");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        11, this->operation(), target);
  }

  // optional int32 int32result = 12;
  if (cached_has_bits & 0x00002000u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(12, this->int32result(), target);
  }

  // optional int64 int64result = 13;
  if (cached_has_bits & 0x00000800u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(13, this->int64result(), target);
  }

  // optional double dbresult = 14;
  if (cached_has_bits & 0x00001000u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(14, this->dbresult(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Message.protobuf.Msg)
  return target;
}

size_t Msg::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:Message.protobuf.Msg)
  size_t total_size = 0;

  if (has_role()) {
    // required int32 role = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->role());
  }

  if (has_msgcategory()) {
    // required int32 msgCategory = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->msgcategory());
  }

  return total_size;
}
size_t Msg::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Message.protobuf.Msg)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x00000018) ^ 0x00000018) == 0) {  // All required fields are present.
    // required int32 role = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->role());

    // required int32 msgCategory = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->msgcategory());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  if (_has_bits_[0 / 32] & 7u) {
    // optional string ip = 3;
    if (has_ip()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->ip());
    }

    // optional string port = 4;
    if (has_port()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->port());
    }

    // optional string operation = 11;
    if (has_operation()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->operation());
    }

  }
  if (_has_bits_[0 / 32] & 224u) {
    // optional int32 int32op1 = 5;
    if (has_int32op1()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->int32op1());
    }

    // optional int32 int32op2 = 6;
    if (has_int32op2()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->int32op2());
    }

    // optional int64 int64op1 = 7;
    if (has_int64op1()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->int64op1());
    }

  }
  if (_has_bits_[8 / 32] & 16128u) {
    // optional int64 int64op2 = 8;
    if (has_int64op2()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->int64op2());
    }

    // optional double dbop1 = 9;
    if (has_dbop1()) {
      total_size += 1 + 8;
    }

    // optional double dbop2 = 10;
    if (has_dbop2()) {
      total_size += 1 + 8;
    }

    // optional int64 int64result = 13;
    if (has_int64result()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->int64result());
    }

    // optional double dbresult = 14;
    if (has_dbresult()) {
      total_size += 1 + 8;
    }

    // optional int32 int32result = 12;
    if (has_int32result()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->int32result());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Msg::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Message.protobuf.Msg)
  GOOGLE_DCHECK_NE(&from, this);
  const Msg* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Msg>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Message.protobuf.Msg)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Message.protobuf.Msg)
    MergeFrom(*source);
  }
}

void Msg::MergeFrom(const Msg& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Message.protobuf.Msg)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 255u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_ip();
      ip_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.ip_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_port();
      port_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.port_);
    }
    if (cached_has_bits & 0x00000004u) {
      set_has_operation();
      operation_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.operation_);
    }
    if (cached_has_bits & 0x00000008u) {
      role_ = from.role_;
    }
    if (cached_has_bits & 0x00000010u) {
      msgcategory_ = from.msgcategory_;
    }
    if (cached_has_bits & 0x00000020u) {
      int32op1_ = from.int32op1_;
    }
    if (cached_has_bits & 0x00000040u) {
      int32op2_ = from.int32op2_;
    }
    if (cached_has_bits & 0x00000080u) {
      int64op1_ = from.int64op1_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  if (cached_has_bits & 16128u) {
    if (cached_has_bits & 0x00000100u) {
      int64op2_ = from.int64op2_;
    }
    if (cached_has_bits & 0x00000200u) {
      dbop1_ = from.dbop1_;
    }
    if (cached_has_bits & 0x00000400u) {
      dbop2_ = from.dbop2_;
    }
    if (cached_has_bits & 0x00000800u) {
      int64result_ = from.int64result_;
    }
    if (cached_has_bits & 0x00001000u) {
      dbresult_ = from.dbresult_;
    }
    if (cached_has_bits & 0x00002000u) {
      int32result_ = from.int32result_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Msg::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Message.protobuf.Msg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Msg::CopyFrom(const Msg& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Message.protobuf.Msg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Msg::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000018) != 0x00000018) return false;
  return true;
}

void Msg::Swap(Msg* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Msg::InternalSwap(Msg* other) {
  using std::swap;
  ip_.Swap(&other->ip_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  port_.Swap(&other->port_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  operation_.Swap(&other->operation_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(role_, other->role_);
  swap(msgcategory_, other->msgcategory_);
  swap(int32op1_, other->int32op1_);
  swap(int32op2_, other->int32op2_);
  swap(int64op1_, other->int64op1_);
  swap(int64op2_, other->int64op2_);
  swap(dbop1_, other->dbop1_);
  swap(dbop2_, other->dbop2_);
  swap(int64result_, other->int64result_);
  swap(dbresult_, other->dbresult_);
  swap(int32result_, other->int32result_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Msg::GetMetadata() const {
  protobuf_Message_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Message_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf
}  // namespace Message
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::Message::protobuf::Msg* Arena::CreateMaybeMessage< ::Message::protobuf::Msg >(Arena* arena) {
  return Arena::CreateInternal< ::Message::protobuf::Msg >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
