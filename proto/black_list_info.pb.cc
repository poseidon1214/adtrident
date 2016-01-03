// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "black_list_info.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace ad {
namespace rtb {

namespace {

const ::google::protobuf::Descriptor* black_list_info_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  black_list_info_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_black_5flist_5finfo_2eproto() {
  protobuf_AddDesc_black_5flist_5finfo_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "black_list_info.proto");
  GOOGLE_CHECK(file != NULL);
  black_list_info_descriptor_ = file->message_type(0);
  static const int black_list_info_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(black_list_info, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(black_list_info, id_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(black_list_info, id_value_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(black_list_info, cdate_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(black_list_info, udate_),
  };
  black_list_info_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      black_list_info_descriptor_,
      black_list_info::default_instance_,
      black_list_info_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(black_list_info, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(black_list_info, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(black_list_info));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_black_5flist_5finfo_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    black_list_info_descriptor_, &black_list_info::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_black_5flist_5finfo_2eproto() {
  delete black_list_info::default_instance_;
  delete black_list_info_reflection_;
}

void protobuf_AddDesc_black_5flist_5finfo_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::xbuiltin::protobuf_AddDesc_xbuiltin_2doptions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\025black_list_info.proto\022\006ad.rtb\032\026xbuilti"
    "n-options.proto\"k\n\017black_list_info\022\n\n\002id"
    "\030\001 \002(\004\022\017\n\007id_type\030\002 \002(\014\022\020\n\010id_value\030\003 \002("
    "\014\022\r\n\005cdate\030\004 \002(\014\022\r\n\005udate\030\005 \002(\014:\013\322>\010id_v"
    "alue", 164);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "black_list_info.proto", &protobuf_RegisterTypes);
  black_list_info::default_instance_ = new black_list_info();
  black_list_info::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_black_5flist_5finfo_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_black_5flist_5finfo_2eproto {
  StaticDescriptorInitializer_black_5flist_5finfo_2eproto() {
    protobuf_AddDesc_black_5flist_5finfo_2eproto();
  }
} static_descriptor_initializer_black_5flist_5finfo_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int black_list_info::kIdFieldNumber;
const int black_list_info::kIdTypeFieldNumber;
const int black_list_info::kIdValueFieldNumber;
const int black_list_info::kCdateFieldNumber;
const int black_list_info::kUdateFieldNumber;
#endif  // !_MSC_VER

black_list_info::black_list_info()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void black_list_info::InitAsDefaultInstance() {
}

black_list_info::black_list_info(const black_list_info& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void black_list_info::SharedCtor() {
  _cached_size_ = 0;
  id_ = GOOGLE_ULONGLONG(0);
  id_type_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  id_value_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  cdate_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  udate_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

black_list_info::~black_list_info() {
  SharedDtor();
}

void black_list_info::SharedDtor() {
  if (id_type_ != &::google::protobuf::internal::kEmptyString) {
    delete id_type_;
  }
  if (id_value_ != &::google::protobuf::internal::kEmptyString) {
    delete id_value_;
  }
  if (cdate_ != &::google::protobuf::internal::kEmptyString) {
    delete cdate_;
  }
  if (udate_ != &::google::protobuf::internal::kEmptyString) {
    delete udate_;
  }
  if (this != default_instance_) {
  }
}

void black_list_info::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* black_list_info::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return black_list_info_descriptor_;
}

const black_list_info& black_list_info::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_black_5flist_5finfo_2eproto();  return *default_instance_;
}

black_list_info* black_list_info::default_instance_ = NULL;

black_list_info* black_list_info::New() const {
  return new black_list_info;
}

void black_list_info::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = GOOGLE_ULONGLONG(0);
    if (has_id_type()) {
      if (id_type_ != &::google::protobuf::internal::kEmptyString) {
        id_type_->clear();
      }
    }
    if (has_id_value()) {
      if (id_value_ != &::google::protobuf::internal::kEmptyString) {
        id_value_->clear();
      }
    }
    if (has_cdate()) {
      if (cdate_ != &::google::protobuf::internal::kEmptyString) {
        cdate_->clear();
      }
    }
    if (has_udate()) {
      if (udate_ != &::google::protobuf::internal::kEmptyString) {
        udate_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool black_list_info::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint64 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_id_type;
        break;
      }
      
      // required bytes id_type = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_id_type:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_id_type()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_id_value;
        break;
      }
      
      // required bytes id_value = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_id_value:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_id_value()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_cdate;
        break;
      }
      
      // required bytes cdate = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_cdate:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_cdate()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_udate;
        break;
      }
      
      // required bytes udate = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_udate:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_udate()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void black_list_info::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint64 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->id(), output);
  }
  
  // required bytes id_type = 2;
  if (has_id_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      2, this->id_type(), output);
  }
  
  // required bytes id_value = 3;
  if (has_id_value()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      3, this->id_value(), output);
  }
  
  // required bytes cdate = 4;
  if (has_cdate()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      4, this->cdate(), output);
  }
  
  // required bytes udate = 5;
  if (has_udate()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      5, this->udate(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* black_list_info::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint64 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->id(), target);
  }
  
  // required bytes id_type = 2;
  if (has_id_type()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->id_type(), target);
  }
  
  // required bytes id_value = 3;
  if (has_id_value()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->id_value(), target);
  }
  
  // required bytes cdate = 4;
  if (has_cdate()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        4, this->cdate(), target);
  }
  
  // required bytes udate = 5;
  if (has_udate()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        5, this->udate(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int black_list_info::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint64 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->id());
    }
    
    // required bytes id_type = 2;
    if (has_id_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->id_type());
    }
    
    // required bytes id_value = 3;
    if (has_id_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->id_value());
    }
    
    // required bytes cdate = 4;
    if (has_cdate()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->cdate());
    }
    
    // required bytes udate = 5;
    if (has_udate()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->udate());
    }
    
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void black_list_info::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const black_list_info* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const black_list_info*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void black_list_info::MergeFrom(const black_list_info& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_id_type()) {
      set_id_type(from.id_type());
    }
    if (from.has_id_value()) {
      set_id_value(from.id_value());
    }
    if (from.has_cdate()) {
      set_cdate(from.cdate());
    }
    if (from.has_udate()) {
      set_udate(from.udate());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void black_list_info::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void black_list_info::CopyFrom(const black_list_info& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool black_list_info::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001f) != 0x0000001f) return false;
  
  return true;
}

void black_list_info::Swap(black_list_info* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(id_type_, other->id_type_);
    std::swap(id_value_, other->id_value_);
    std::swap(cdate_, other->cdate_);
    std::swap(udate_, other->udate_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata black_list_info::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = black_list_info_descriptor_;
  metadata.reflection = black_list_info_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace rtb
}  // namespace ad

// @@protoc_insertion_point(global_scope)
