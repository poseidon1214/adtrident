// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "idea_info.pb.h"

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

const ::google::protobuf::Descriptor* idea_info_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  idea_info_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_idea_5finfo_2eproto() {
  protobuf_AddDesc_idea_5finfo_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "idea_info.proto");
  GOOGLE_CHECK(file != NULL);
  idea_info_descriptor_ = file->message_type(0);
  static const int idea_info_offsets_[15] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, level_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, ideaid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, unitid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, planid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, userid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, title_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, desc1_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, url_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, showurl_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, creative_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, width_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, height_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, path_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, cdate_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, udate_),
  };
  idea_info_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      idea_info_descriptor_,
      idea_info::default_instance_,
      idea_info_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(idea_info, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(idea_info));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_idea_5finfo_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    idea_info_descriptor_, &idea_info::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_idea_5finfo_2eproto() {
  delete idea_info::default_instance_;
  delete idea_info_reflection_;
}

void protobuf_AddDesc_idea_5finfo_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::xbuiltin::protobuf_AddDesc_xbuiltin_2doptions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017idea_info.proto\022\006ad.rtb\032\026xbuiltin-opti"
    "ons.proto\"\203\002\n\tidea_info\022\r\n\005level\030\001 \001(\004\022\016"
    "\n\006ideaid\030\002 \002(\004\022\016\n\006unitid\030\003 \002(\004\022\016\n\006planid"
    "\030\004 \002(\004\022\016\n\006userid\030\005 \002(\004\022\r\n\005title\030\006 \001(\014\022\r\n"
    "\005desc1\030\007 \001(\014\022\013\n\003url\030\010 \001(\014\022\017\n\007showurl\030\t \001"
    "(\014\022\025\n\rcreative_type\030\n \002(\r\022\r\n\005width\030\013 \002(\r"
    "\022\016\n\006height\030\014 \002(\r\022\014\n\004path\030\r \002(\014\022\r\n\005cdate\030"
    "\016 \002(\014\022\r\n\005udate\030\017 \002(\014:\t\322>\006ideaid", 311);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "idea_info.proto", &protobuf_RegisterTypes);
  idea_info::default_instance_ = new idea_info();
  idea_info::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_idea_5finfo_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_idea_5finfo_2eproto {
  StaticDescriptorInitializer_idea_5finfo_2eproto() {
    protobuf_AddDesc_idea_5finfo_2eproto();
  }
} static_descriptor_initializer_idea_5finfo_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int idea_info::kLevelFieldNumber;
const int idea_info::kIdeaidFieldNumber;
const int idea_info::kUnitidFieldNumber;
const int idea_info::kPlanidFieldNumber;
const int idea_info::kUseridFieldNumber;
const int idea_info::kTitleFieldNumber;
const int idea_info::kDesc1FieldNumber;
const int idea_info::kUrlFieldNumber;
const int idea_info::kShowurlFieldNumber;
const int idea_info::kCreativeTypeFieldNumber;
const int idea_info::kWidthFieldNumber;
const int idea_info::kHeightFieldNumber;
const int idea_info::kPathFieldNumber;
const int idea_info::kCdateFieldNumber;
const int idea_info::kUdateFieldNumber;
#endif  // !_MSC_VER

idea_info::idea_info()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void idea_info::InitAsDefaultInstance() {
}

idea_info::idea_info(const idea_info& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void idea_info::SharedCtor() {
  _cached_size_ = 0;
  level_ = GOOGLE_ULONGLONG(0);
  ideaid_ = GOOGLE_ULONGLONG(0);
  unitid_ = GOOGLE_ULONGLONG(0);
  planid_ = GOOGLE_ULONGLONG(0);
  userid_ = GOOGLE_ULONGLONG(0);
  title_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  desc1_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  url_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  showurl_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  creative_type_ = 0u;
  width_ = 0u;
  height_ = 0u;
  path_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  cdate_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  udate_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

idea_info::~idea_info() {
  SharedDtor();
}

void idea_info::SharedDtor() {
  if (title_ != &::google::protobuf::internal::kEmptyString) {
    delete title_;
  }
  if (desc1_ != &::google::protobuf::internal::kEmptyString) {
    delete desc1_;
  }
  if (url_ != &::google::protobuf::internal::kEmptyString) {
    delete url_;
  }
  if (showurl_ != &::google::protobuf::internal::kEmptyString) {
    delete showurl_;
  }
  if (path_ != &::google::protobuf::internal::kEmptyString) {
    delete path_;
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

void idea_info::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* idea_info::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return idea_info_descriptor_;
}

const idea_info& idea_info::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_idea_5finfo_2eproto();  return *default_instance_;
}

idea_info* idea_info::default_instance_ = NULL;

idea_info* idea_info::New() const {
  return new idea_info;
}

void idea_info::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    level_ = GOOGLE_ULONGLONG(0);
    ideaid_ = GOOGLE_ULONGLONG(0);
    unitid_ = GOOGLE_ULONGLONG(0);
    planid_ = GOOGLE_ULONGLONG(0);
    userid_ = GOOGLE_ULONGLONG(0);
    if (has_title()) {
      if (title_ != &::google::protobuf::internal::kEmptyString) {
        title_->clear();
      }
    }
    if (has_desc1()) {
      if (desc1_ != &::google::protobuf::internal::kEmptyString) {
        desc1_->clear();
      }
    }
    if (has_url()) {
      if (url_ != &::google::protobuf::internal::kEmptyString) {
        url_->clear();
      }
    }
  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (has_showurl()) {
      if (showurl_ != &::google::protobuf::internal::kEmptyString) {
        showurl_->clear();
      }
    }
    creative_type_ = 0u;
    width_ = 0u;
    height_ = 0u;
    if (has_path()) {
      if (path_ != &::google::protobuf::internal::kEmptyString) {
        path_->clear();
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

bool idea_info::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint64 level = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &level_)));
          set_has_level();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_ideaid;
        break;
      }
      
      // required uint64 ideaid = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_ideaid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &ideaid_)));
          set_has_ideaid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_unitid;
        break;
      }
      
      // required uint64 unitid = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_unitid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &unitid_)));
          set_has_unitid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_planid;
        break;
      }
      
      // required uint64 planid = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_planid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &planid_)));
          set_has_planid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_userid;
        break;
      }
      
      // required uint64 userid = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_userid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &userid_)));
          set_has_userid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(50)) goto parse_title;
        break;
      }
      
      // optional bytes title = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_title:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_title()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(58)) goto parse_desc1;
        break;
      }
      
      // optional bytes desc1 = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_desc1:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_desc1()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(66)) goto parse_url;
        break;
      }
      
      // optional bytes url = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_url:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_url()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(74)) goto parse_showurl;
        break;
      }
      
      // optional bytes showurl = 9;
      case 9: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_showurl:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_showurl()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(80)) goto parse_creative_type;
        break;
      }
      
      // required uint32 creative_type = 10;
      case 10: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_creative_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &creative_type_)));
          set_has_creative_type();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(88)) goto parse_width;
        break;
      }
      
      // required uint32 width = 11;
      case 11: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_width:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &width_)));
          set_has_width();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(96)) goto parse_height;
        break;
      }
      
      // required uint32 height = 12;
      case 12: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_height:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &height_)));
          set_has_height();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(106)) goto parse_path;
        break;
      }
      
      // required bytes path = 13;
      case 13: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_path:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_path()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(114)) goto parse_cdate;
        break;
      }
      
      // required bytes cdate = 14;
      case 14: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_cdate:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_cdate()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(122)) goto parse_udate;
        break;
      }
      
      // required bytes udate = 15;
      case 15: {
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

void idea_info::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional uint64 level = 1;
  if (has_level()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->level(), output);
  }
  
  // required uint64 ideaid = 2;
  if (has_ideaid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->ideaid(), output);
  }
  
  // required uint64 unitid = 3;
  if (has_unitid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->unitid(), output);
  }
  
  // required uint64 planid = 4;
  if (has_planid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->planid(), output);
  }
  
  // required uint64 userid = 5;
  if (has_userid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(5, this->userid(), output);
  }
  
  // optional bytes title = 6;
  if (has_title()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      6, this->title(), output);
  }
  
  // optional bytes desc1 = 7;
  if (has_desc1()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      7, this->desc1(), output);
  }
  
  // optional bytes url = 8;
  if (has_url()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      8, this->url(), output);
  }
  
  // optional bytes showurl = 9;
  if (has_showurl()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      9, this->showurl(), output);
  }
  
  // required uint32 creative_type = 10;
  if (has_creative_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(10, this->creative_type(), output);
  }
  
  // required uint32 width = 11;
  if (has_width()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(11, this->width(), output);
  }
  
  // required uint32 height = 12;
  if (has_height()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(12, this->height(), output);
  }
  
  // required bytes path = 13;
  if (has_path()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      13, this->path(), output);
  }
  
  // required bytes cdate = 14;
  if (has_cdate()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      14, this->cdate(), output);
  }
  
  // required bytes udate = 15;
  if (has_udate()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      15, this->udate(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* idea_info::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional uint64 level = 1;
  if (has_level()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->level(), target);
  }
  
  // required uint64 ideaid = 2;
  if (has_ideaid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->ideaid(), target);
  }
  
  // required uint64 unitid = 3;
  if (has_unitid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->unitid(), target);
  }
  
  // required uint64 planid = 4;
  if (has_planid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->planid(), target);
  }
  
  // required uint64 userid = 5;
  if (has_userid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(5, this->userid(), target);
  }
  
  // optional bytes title = 6;
  if (has_title()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        6, this->title(), target);
  }
  
  // optional bytes desc1 = 7;
  if (has_desc1()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        7, this->desc1(), target);
  }
  
  // optional bytes url = 8;
  if (has_url()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        8, this->url(), target);
  }
  
  // optional bytes showurl = 9;
  if (has_showurl()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        9, this->showurl(), target);
  }
  
  // required uint32 creative_type = 10;
  if (has_creative_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(10, this->creative_type(), target);
  }
  
  // required uint32 width = 11;
  if (has_width()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(11, this->width(), target);
  }
  
  // required uint32 height = 12;
  if (has_height()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(12, this->height(), target);
  }
  
  // required bytes path = 13;
  if (has_path()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        13, this->path(), target);
  }
  
  // required bytes cdate = 14;
  if (has_cdate()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        14, this->cdate(), target);
  }
  
  // required bytes udate = 15;
  if (has_udate()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        15, this->udate(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int idea_info::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint64 level = 1;
    if (has_level()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->level());
    }
    
    // required uint64 ideaid = 2;
    if (has_ideaid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->ideaid());
    }
    
    // required uint64 unitid = 3;
    if (has_unitid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->unitid());
    }
    
    // required uint64 planid = 4;
    if (has_planid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->planid());
    }
    
    // required uint64 userid = 5;
    if (has_userid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->userid());
    }
    
    // optional bytes title = 6;
    if (has_title()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->title());
    }
    
    // optional bytes desc1 = 7;
    if (has_desc1()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->desc1());
    }
    
    // optional bytes url = 8;
    if (has_url()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->url());
    }
    
  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional bytes showurl = 9;
    if (has_showurl()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->showurl());
    }
    
    // required uint32 creative_type = 10;
    if (has_creative_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->creative_type());
    }
    
    // required uint32 width = 11;
    if (has_width()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->width());
    }
    
    // required uint32 height = 12;
    if (has_height()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->height());
    }
    
    // required bytes path = 13;
    if (has_path()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->path());
    }
    
    // required bytes cdate = 14;
    if (has_cdate()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->cdate());
    }
    
    // required bytes udate = 15;
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

void idea_info::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const idea_info* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const idea_info*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void idea_info::MergeFrom(const idea_info& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_level()) {
      set_level(from.level());
    }
    if (from.has_ideaid()) {
      set_ideaid(from.ideaid());
    }
    if (from.has_unitid()) {
      set_unitid(from.unitid());
    }
    if (from.has_planid()) {
      set_planid(from.planid());
    }
    if (from.has_userid()) {
      set_userid(from.userid());
    }
    if (from.has_title()) {
      set_title(from.title());
    }
    if (from.has_desc1()) {
      set_desc1(from.desc1());
    }
    if (from.has_url()) {
      set_url(from.url());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_showurl()) {
      set_showurl(from.showurl());
    }
    if (from.has_creative_type()) {
      set_creative_type(from.creative_type());
    }
    if (from.has_width()) {
      set_width(from.width());
    }
    if (from.has_height()) {
      set_height(from.height());
    }
    if (from.has_path()) {
      set_path(from.path());
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

void idea_info::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void idea_info::CopyFrom(const idea_info& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool idea_info::IsInitialized() const {
  if ((_has_bits_[0] & 0x00007e1e) != 0x00007e1e) return false;
  
  return true;
}

void idea_info::Swap(idea_info* other) {
  if (other != this) {
    std::swap(level_, other->level_);
    std::swap(ideaid_, other->ideaid_);
    std::swap(unitid_, other->unitid_);
    std::swap(planid_, other->planid_);
    std::swap(userid_, other->userid_);
    std::swap(title_, other->title_);
    std::swap(desc1_, other->desc1_);
    std::swap(url_, other->url_);
    std::swap(showurl_, other->showurl_);
    std::swap(creative_type_, other->creative_type_);
    std::swap(width_, other->width_);
    std::swap(height_, other->height_);
    std::swap(path_, other->path_);
    std::swap(cdate_, other->cdate_);
    std::swap(udate_, other->udate_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata idea_info::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = idea_info_descriptor_;
  metadata.reflection = idea_info_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace rtb
}  // namespace ad

// @@protoc_insertion_point(global_scope)
