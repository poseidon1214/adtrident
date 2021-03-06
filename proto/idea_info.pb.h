// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: idea_info.proto

#ifndef PROTOBUF_idea_5finfo_2eproto__INCLUDED
#define PROTOBUF_idea_5finfo_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
#include "xbuiltin-options.pb.h"
#include <xbuiltin/Utils.h>
// @@protoc_insertion_point(includes)

namespace ad {
namespace rtb {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_idea_5finfo_2eproto();
void protobuf_AssignDesc_idea_5finfo_2eproto();
void protobuf_ShutdownFile_idea_5finfo_2eproto();

class idea_info;

// ===================================================================

class idea_info : public ::google::protobuf::Message {
 public:
  idea_info();
  virtual ~idea_info();
  
  idea_info(const idea_info& from);
  
  inline idea_info& operator=(const idea_info& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const idea_info& default_instance();
  
  void Swap(idea_info* other);
  
  // implements Message ----------------------------------------------
  
  idea_info* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const idea_info& from);
  void MergeFrom(const idea_info& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // optional uint64 level = 1;
  inline bool has_level() const;
  inline void clear_level();
  static const int kLevelFieldNumber = 1;
  inline ::google::protobuf::uint64 level() const;
  inline void set_level(::google::protobuf::uint64 value);
  
  // required uint64 ideaid = 2;
  inline bool has_ideaid() const;
  inline void clear_ideaid();
  static const int kIdeaidFieldNumber = 2;
  inline ::google::protobuf::uint64 ideaid() const;
  inline void set_ideaid(::google::protobuf::uint64 value);
  
  // required uint64 unitid = 3;
  inline bool has_unitid() const;
  inline void clear_unitid();
  static const int kUnitidFieldNumber = 3;
  inline ::google::protobuf::uint64 unitid() const;
  inline void set_unitid(::google::protobuf::uint64 value);
  
  // required uint64 planid = 4;
  inline bool has_planid() const;
  inline void clear_planid();
  static const int kPlanidFieldNumber = 4;
  inline ::google::protobuf::uint64 planid() const;
  inline void set_planid(::google::protobuf::uint64 value);
  
  // required uint64 userid = 5;
  inline bool has_userid() const;
  inline void clear_userid();
  static const int kUseridFieldNumber = 5;
  inline ::google::protobuf::uint64 userid() const;
  inline void set_userid(::google::protobuf::uint64 value);
  
  // optional bytes title = 6;
  inline bool has_title() const;
  inline void clear_title();
  static const int kTitleFieldNumber = 6;
  inline const ::std::string& title() const;
  inline void set_title(const ::std::string& value);
  inline void set_title(const char* value);
  inline void set_title(const void* value, size_t size);
  inline ::std::string* mutable_title();
  inline ::std::string* release_title();
  
  // optional bytes desc1 = 7;
  inline bool has_desc1() const;
  inline void clear_desc1();
  static const int kDesc1FieldNumber = 7;
  inline const ::std::string& desc1() const;
  inline void set_desc1(const ::std::string& value);
  inline void set_desc1(const char* value);
  inline void set_desc1(const void* value, size_t size);
  inline ::std::string* mutable_desc1();
  inline ::std::string* release_desc1();
  
  // optional bytes url = 8;
  inline bool has_url() const;
  inline void clear_url();
  static const int kUrlFieldNumber = 8;
  inline const ::std::string& url() const;
  inline void set_url(const ::std::string& value);
  inline void set_url(const char* value);
  inline void set_url(const void* value, size_t size);
  inline ::std::string* mutable_url();
  inline ::std::string* release_url();
  
  // optional bytes showurl = 9;
  inline bool has_showurl() const;
  inline void clear_showurl();
  static const int kShowurlFieldNumber = 9;
  inline const ::std::string& showurl() const;
  inline void set_showurl(const ::std::string& value);
  inline void set_showurl(const char* value);
  inline void set_showurl(const void* value, size_t size);
  inline ::std::string* mutable_showurl();
  inline ::std::string* release_showurl();
  
  // required uint32 creative_type = 10;
  inline bool has_creative_type() const;
  inline void clear_creative_type();
  static const int kCreativeTypeFieldNumber = 10;
  inline ::google::protobuf::uint32 creative_type() const;
  inline void set_creative_type(::google::protobuf::uint32 value);
  
  // required uint32 width = 11;
  inline bool has_width() const;
  inline void clear_width();
  static const int kWidthFieldNumber = 11;
  inline ::google::protobuf::uint32 width() const;
  inline void set_width(::google::protobuf::uint32 value);
  
  // required uint32 height = 12;
  inline bool has_height() const;
  inline void clear_height();
  static const int kHeightFieldNumber = 12;
  inline ::google::protobuf::uint32 height() const;
  inline void set_height(::google::protobuf::uint32 value);
  
  // required bytes path = 13;
  inline bool has_path() const;
  inline void clear_path();
  static const int kPathFieldNumber = 13;
  inline const ::std::string& path() const;
  inline void set_path(const ::std::string& value);
  inline void set_path(const char* value);
  inline void set_path(const void* value, size_t size);
  inline ::std::string* mutable_path();
  inline ::std::string* release_path();
  
  // required bytes cdate = 14;
  inline bool has_cdate() const;
  inline void clear_cdate();
  static const int kCdateFieldNumber = 14;
  inline const ::std::string& cdate() const;
  inline void set_cdate(const ::std::string& value);
  inline void set_cdate(const char* value);
  inline void set_cdate(const void* value, size_t size);
  inline ::std::string* mutable_cdate();
  inline ::std::string* release_cdate();
  
  // required bytes udate = 15;
  inline bool has_udate() const;
  inline void clear_udate();
  static const int kUdateFieldNumber = 15;
  inline const ::std::string& udate() const;
  inline void set_udate(const ::std::string& value);
  inline void set_udate(const char* value);
  inline void set_udate(const void* value, size_t size);
  inline ::std::string* mutable_udate();
  inline ::std::string* release_udate();
  
  static inline int generate_keysign(const uint64_t xdict_ideaid, uint64_t *output) {
    if (::xbuiltin::make_sign64(xdict_ideaid, output) < 0) {
      return -1;
    }
    return 0;
  }
  int generate_keysign(uint64_t *output) {
    return generate_keysign(ideaid(), output);
  }
  void clear_optionals() {
  }
  int load_tsl(char *&str) {
    // level
    uint64_t xdict_level_value;
    if (::xbuiltin::xconvert(str, &xdict_level_value) < 0) {
      return -1;
    }
    set_level(xdict_level_value);
    // ideaid
    uint64_t xdict_ideaid_value;
    if (::xbuiltin::xconvert(str, &xdict_ideaid_value) < 0) {
      return -1;
    }
    set_ideaid(xdict_ideaid_value);
    // unitid
    uint64_t xdict_unitid_value;
    if (::xbuiltin::xconvert(str, &xdict_unitid_value) < 0) {
      return -1;
    }
    set_unitid(xdict_unitid_value);
    // planid
    uint64_t xdict_planid_value;
    if (::xbuiltin::xconvert(str, &xdict_planid_value) < 0) {
      return -1;
    }
    set_planid(xdict_planid_value);
    // userid
    uint64_t xdict_userid_value;
    if (::xbuiltin::xconvert(str, &xdict_userid_value) < 0) {
      return -1;
    }
    set_userid(xdict_userid_value);
    // title
    char * xdict_title_value;
    if (::xbuiltin::xconvert(str, &xdict_title_value) < 0) {
      return -1;
    }
    set_title(xdict_title_value);
    // desc1
    char * xdict_desc1_value;
    if (::xbuiltin::xconvert(str, &xdict_desc1_value) < 0) {
      return -1;
    }
    set_desc1(xdict_desc1_value);
    // url
    char * xdict_url_value;
    if (::xbuiltin::xconvert(str, &xdict_url_value) < 0) {
      return -1;
    }
    set_url(xdict_url_value);
    // showurl
    char * xdict_showurl_value;
    if (::xbuiltin::xconvert(str, &xdict_showurl_value) < 0) {
      return -1;
    }
    set_showurl(xdict_showurl_value);
    // creative_type
    uint32_t xdict_creative_type_value;
    if (::xbuiltin::xconvert(str, &xdict_creative_type_value) < 0) {
      return -1;
    }
    set_creative_type(xdict_creative_type_value);
    // width
    uint32_t xdict_width_value;
    if (::xbuiltin::xconvert(str, &xdict_width_value) < 0) {
      return -1;
    }
    set_width(xdict_width_value);
    // height
    uint32_t xdict_height_value;
    if (::xbuiltin::xconvert(str, &xdict_height_value) < 0) {
      return -1;
    }
    set_height(xdict_height_value);
    // path
    char * xdict_path_value;
    if (::xbuiltin::xconvert(str, &xdict_path_value) < 0) {
      return -1;
    }
    set_path(xdict_path_value);
    // cdate
    char * xdict_cdate_value;
    if (::xbuiltin::xconvert(str, &xdict_cdate_value) < 0) {
      return -1;
    }
    set_cdate(xdict_cdate_value);
    // udate
    char * xdict_udate_value;
    if (::xbuiltin::xconvert(str, &xdict_udate_value) < 0) {
      return -1;
    }
    set_udate(xdict_udate_value);
    return 0;
  }
  // @@protoc_insertion_point(class_scope:ad.rtb.idea_info)
 private:
  inline void set_has_level();
  inline void clear_has_level();
  inline void set_has_ideaid();
  inline void clear_has_ideaid();
  inline void set_has_unitid();
  inline void clear_has_unitid();
  inline void set_has_planid();
  inline void clear_has_planid();
  inline void set_has_userid();
  inline void clear_has_userid();
  inline void set_has_title();
  inline void clear_has_title();
  inline void set_has_desc1();
  inline void clear_has_desc1();
  inline void set_has_url();
  inline void clear_has_url();
  inline void set_has_showurl();
  inline void clear_has_showurl();
  inline void set_has_creative_type();
  inline void clear_has_creative_type();
  inline void set_has_width();
  inline void clear_has_width();
  inline void set_has_height();
  inline void clear_has_height();
  inline void set_has_path();
  inline void clear_has_path();
  inline void set_has_cdate();
  inline void clear_has_cdate();
  inline void set_has_udate();
  inline void clear_has_udate();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::uint64 level_;
  ::google::protobuf::uint64 ideaid_;
  ::google::protobuf::uint64 unitid_;
  ::google::protobuf::uint64 planid_;
  ::google::protobuf::uint64 userid_;
  ::std::string* title_;
  ::std::string* desc1_;
  ::std::string* url_;
  ::std::string* showurl_;
  ::google::protobuf::uint32 creative_type_;
  ::google::protobuf::uint32 width_;
  ::std::string* path_;
  ::std::string* cdate_;
  ::std::string* udate_;
  ::google::protobuf::uint32 height_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(15 + 31) / 32];
  
  friend void  protobuf_AddDesc_idea_5finfo_2eproto();
  friend void protobuf_AssignDesc_idea_5finfo_2eproto();
  friend void protobuf_ShutdownFile_idea_5finfo_2eproto();
  
  void InitAsDefaultInstance();
  static idea_info* default_instance_;
};
// ===================================================================


// ===================================================================

// idea_info

// optional uint64 level = 1;
inline bool idea_info::has_level() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void idea_info::set_has_level() {
  _has_bits_[0] |= 0x00000001u;
}
inline void idea_info::clear_has_level() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void idea_info::clear_level() {
  level_ = GOOGLE_ULONGLONG(0);
  clear_has_level();
}
inline ::google::protobuf::uint64 idea_info::level() const {
  return level_;
}
inline void idea_info::set_level(::google::protobuf::uint64 value) {
  set_has_level();
  level_ = value;
}

// required uint64 ideaid = 2;
inline bool idea_info::has_ideaid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void idea_info::set_has_ideaid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void idea_info::clear_has_ideaid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void idea_info::clear_ideaid() {
  ideaid_ = GOOGLE_ULONGLONG(0);
  clear_has_ideaid();
}
inline ::google::protobuf::uint64 idea_info::ideaid() const {
  return ideaid_;
}
inline void idea_info::set_ideaid(::google::protobuf::uint64 value) {
  set_has_ideaid();
  ideaid_ = value;
}

// required uint64 unitid = 3;
inline bool idea_info::has_unitid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void idea_info::set_has_unitid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void idea_info::clear_has_unitid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void idea_info::clear_unitid() {
  unitid_ = GOOGLE_ULONGLONG(0);
  clear_has_unitid();
}
inline ::google::protobuf::uint64 idea_info::unitid() const {
  return unitid_;
}
inline void idea_info::set_unitid(::google::protobuf::uint64 value) {
  set_has_unitid();
  unitid_ = value;
}

// required uint64 planid = 4;
inline bool idea_info::has_planid() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void idea_info::set_has_planid() {
  _has_bits_[0] |= 0x00000008u;
}
inline void idea_info::clear_has_planid() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void idea_info::clear_planid() {
  planid_ = GOOGLE_ULONGLONG(0);
  clear_has_planid();
}
inline ::google::protobuf::uint64 idea_info::planid() const {
  return planid_;
}
inline void idea_info::set_planid(::google::protobuf::uint64 value) {
  set_has_planid();
  planid_ = value;
}

// required uint64 userid = 5;
inline bool idea_info::has_userid() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void idea_info::set_has_userid() {
  _has_bits_[0] |= 0x00000010u;
}
inline void idea_info::clear_has_userid() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void idea_info::clear_userid() {
  userid_ = GOOGLE_ULONGLONG(0);
  clear_has_userid();
}
inline ::google::protobuf::uint64 idea_info::userid() const {
  return userid_;
}
inline void idea_info::set_userid(::google::protobuf::uint64 value) {
  set_has_userid();
  userid_ = value;
}

// optional bytes title = 6;
inline bool idea_info::has_title() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void idea_info::set_has_title() {
  _has_bits_[0] |= 0x00000020u;
}
inline void idea_info::clear_has_title() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void idea_info::clear_title() {
  if (title_ != &::google::protobuf::internal::kEmptyString) {
    title_->clear();
  }
  clear_has_title();
}
inline const ::std::string& idea_info::title() const {
  return *title_;
}
inline void idea_info::set_title(const ::std::string& value) {
  set_has_title();
  if (title_ == &::google::protobuf::internal::kEmptyString) {
    title_ = new ::std::string;
  }
  title_->assign(value);
}
inline void idea_info::set_title(const char* value) {
  set_has_title();
  if (title_ == &::google::protobuf::internal::kEmptyString) {
    title_ = new ::std::string;
  }
  title_->assign(value);
}
inline void idea_info::set_title(const void* value, size_t size) {
  set_has_title();
  if (title_ == &::google::protobuf::internal::kEmptyString) {
    title_ = new ::std::string;
  }
  title_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* idea_info::mutable_title() {
  set_has_title();
  if (title_ == &::google::protobuf::internal::kEmptyString) {
    title_ = new ::std::string;
  }
  return title_;
}
inline ::std::string* idea_info::release_title() {
  clear_has_title();
  if (title_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = title_;
    title_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional bytes desc1 = 7;
inline bool idea_info::has_desc1() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void idea_info::set_has_desc1() {
  _has_bits_[0] |= 0x00000040u;
}
inline void idea_info::clear_has_desc1() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void idea_info::clear_desc1() {
  if (desc1_ != &::google::protobuf::internal::kEmptyString) {
    desc1_->clear();
  }
  clear_has_desc1();
}
inline const ::std::string& idea_info::desc1() const {
  return *desc1_;
}
inline void idea_info::set_desc1(const ::std::string& value) {
  set_has_desc1();
  if (desc1_ == &::google::protobuf::internal::kEmptyString) {
    desc1_ = new ::std::string;
  }
  desc1_->assign(value);
}
inline void idea_info::set_desc1(const char* value) {
  set_has_desc1();
  if (desc1_ == &::google::protobuf::internal::kEmptyString) {
    desc1_ = new ::std::string;
  }
  desc1_->assign(value);
}
inline void idea_info::set_desc1(const void* value, size_t size) {
  set_has_desc1();
  if (desc1_ == &::google::protobuf::internal::kEmptyString) {
    desc1_ = new ::std::string;
  }
  desc1_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* idea_info::mutable_desc1() {
  set_has_desc1();
  if (desc1_ == &::google::protobuf::internal::kEmptyString) {
    desc1_ = new ::std::string;
  }
  return desc1_;
}
inline ::std::string* idea_info::release_desc1() {
  clear_has_desc1();
  if (desc1_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = desc1_;
    desc1_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional bytes url = 8;
inline bool idea_info::has_url() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void idea_info::set_has_url() {
  _has_bits_[0] |= 0x00000080u;
}
inline void idea_info::clear_has_url() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void idea_info::clear_url() {
  if (url_ != &::google::protobuf::internal::kEmptyString) {
    url_->clear();
  }
  clear_has_url();
}
inline const ::std::string& idea_info::url() const {
  return *url_;
}
inline void idea_info::set_url(const ::std::string& value) {
  set_has_url();
  if (url_ == &::google::protobuf::internal::kEmptyString) {
    url_ = new ::std::string;
  }
  url_->assign(value);
}
inline void idea_info::set_url(const char* value) {
  set_has_url();
  if (url_ == &::google::protobuf::internal::kEmptyString) {
    url_ = new ::std::string;
  }
  url_->assign(value);
}
inline void idea_info::set_url(const void* value, size_t size) {
  set_has_url();
  if (url_ == &::google::protobuf::internal::kEmptyString) {
    url_ = new ::std::string;
  }
  url_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* idea_info::mutable_url() {
  set_has_url();
  if (url_ == &::google::protobuf::internal::kEmptyString) {
    url_ = new ::std::string;
  }
  return url_;
}
inline ::std::string* idea_info::release_url() {
  clear_has_url();
  if (url_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = url_;
    url_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional bytes showurl = 9;
inline bool idea_info::has_showurl() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void idea_info::set_has_showurl() {
  _has_bits_[0] |= 0x00000100u;
}
inline void idea_info::clear_has_showurl() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void idea_info::clear_showurl() {
  if (showurl_ != &::google::protobuf::internal::kEmptyString) {
    showurl_->clear();
  }
  clear_has_showurl();
}
inline const ::std::string& idea_info::showurl() const {
  return *showurl_;
}
inline void idea_info::set_showurl(const ::std::string& value) {
  set_has_showurl();
  if (showurl_ == &::google::protobuf::internal::kEmptyString) {
    showurl_ = new ::std::string;
  }
  showurl_->assign(value);
}
inline void idea_info::set_showurl(const char* value) {
  set_has_showurl();
  if (showurl_ == &::google::protobuf::internal::kEmptyString) {
    showurl_ = new ::std::string;
  }
  showurl_->assign(value);
}
inline void idea_info::set_showurl(const void* value, size_t size) {
  set_has_showurl();
  if (showurl_ == &::google::protobuf::internal::kEmptyString) {
    showurl_ = new ::std::string;
  }
  showurl_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* idea_info::mutable_showurl() {
  set_has_showurl();
  if (showurl_ == &::google::protobuf::internal::kEmptyString) {
    showurl_ = new ::std::string;
  }
  return showurl_;
}
inline ::std::string* idea_info::release_showurl() {
  clear_has_showurl();
  if (showurl_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = showurl_;
    showurl_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required uint32 creative_type = 10;
inline bool idea_info::has_creative_type() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void idea_info::set_has_creative_type() {
  _has_bits_[0] |= 0x00000200u;
}
inline void idea_info::clear_has_creative_type() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void idea_info::clear_creative_type() {
  creative_type_ = 0u;
  clear_has_creative_type();
}
inline ::google::protobuf::uint32 idea_info::creative_type() const {
  return creative_type_;
}
inline void idea_info::set_creative_type(::google::protobuf::uint32 value) {
  set_has_creative_type();
  creative_type_ = value;
}

// required uint32 width = 11;
inline bool idea_info::has_width() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void idea_info::set_has_width() {
  _has_bits_[0] |= 0x00000400u;
}
inline void idea_info::clear_has_width() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void idea_info::clear_width() {
  width_ = 0u;
  clear_has_width();
}
inline ::google::protobuf::uint32 idea_info::width() const {
  return width_;
}
inline void idea_info::set_width(::google::protobuf::uint32 value) {
  set_has_width();
  width_ = value;
}

// required uint32 height = 12;
inline bool idea_info::has_height() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void idea_info::set_has_height() {
  _has_bits_[0] |= 0x00000800u;
}
inline void idea_info::clear_has_height() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void idea_info::clear_height() {
  height_ = 0u;
  clear_has_height();
}
inline ::google::protobuf::uint32 idea_info::height() const {
  return height_;
}
inline void idea_info::set_height(::google::protobuf::uint32 value) {
  set_has_height();
  height_ = value;
}

// required bytes path = 13;
inline bool idea_info::has_path() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void idea_info::set_has_path() {
  _has_bits_[0] |= 0x00001000u;
}
inline void idea_info::clear_has_path() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void idea_info::clear_path() {
  if (path_ != &::google::protobuf::internal::kEmptyString) {
    path_->clear();
  }
  clear_has_path();
}
inline const ::std::string& idea_info::path() const {
  return *path_;
}
inline void idea_info::set_path(const ::std::string& value) {
  set_has_path();
  if (path_ == &::google::protobuf::internal::kEmptyString) {
    path_ = new ::std::string;
  }
  path_->assign(value);
}
inline void idea_info::set_path(const char* value) {
  set_has_path();
  if (path_ == &::google::protobuf::internal::kEmptyString) {
    path_ = new ::std::string;
  }
  path_->assign(value);
}
inline void idea_info::set_path(const void* value, size_t size) {
  set_has_path();
  if (path_ == &::google::protobuf::internal::kEmptyString) {
    path_ = new ::std::string;
  }
  path_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* idea_info::mutable_path() {
  set_has_path();
  if (path_ == &::google::protobuf::internal::kEmptyString) {
    path_ = new ::std::string;
  }
  return path_;
}
inline ::std::string* idea_info::release_path() {
  clear_has_path();
  if (path_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = path_;
    path_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required bytes cdate = 14;
inline bool idea_info::has_cdate() const {
  return (_has_bits_[0] & 0x00002000u) != 0;
}
inline void idea_info::set_has_cdate() {
  _has_bits_[0] |= 0x00002000u;
}
inline void idea_info::clear_has_cdate() {
  _has_bits_[0] &= ~0x00002000u;
}
inline void idea_info::clear_cdate() {
  if (cdate_ != &::google::protobuf::internal::kEmptyString) {
    cdate_->clear();
  }
  clear_has_cdate();
}
inline const ::std::string& idea_info::cdate() const {
  return *cdate_;
}
inline void idea_info::set_cdate(const ::std::string& value) {
  set_has_cdate();
  if (cdate_ == &::google::protobuf::internal::kEmptyString) {
    cdate_ = new ::std::string;
  }
  cdate_->assign(value);
}
inline void idea_info::set_cdate(const char* value) {
  set_has_cdate();
  if (cdate_ == &::google::protobuf::internal::kEmptyString) {
    cdate_ = new ::std::string;
  }
  cdate_->assign(value);
}
inline void idea_info::set_cdate(const void* value, size_t size) {
  set_has_cdate();
  if (cdate_ == &::google::protobuf::internal::kEmptyString) {
    cdate_ = new ::std::string;
  }
  cdate_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* idea_info::mutable_cdate() {
  set_has_cdate();
  if (cdate_ == &::google::protobuf::internal::kEmptyString) {
    cdate_ = new ::std::string;
  }
  return cdate_;
}
inline ::std::string* idea_info::release_cdate() {
  clear_has_cdate();
  if (cdate_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = cdate_;
    cdate_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required bytes udate = 15;
inline bool idea_info::has_udate() const {
  return (_has_bits_[0] & 0x00004000u) != 0;
}
inline void idea_info::set_has_udate() {
  _has_bits_[0] |= 0x00004000u;
}
inline void idea_info::clear_has_udate() {
  _has_bits_[0] &= ~0x00004000u;
}
inline void idea_info::clear_udate() {
  if (udate_ != &::google::protobuf::internal::kEmptyString) {
    udate_->clear();
  }
  clear_has_udate();
}
inline const ::std::string& idea_info::udate() const {
  return *udate_;
}
inline void idea_info::set_udate(const ::std::string& value) {
  set_has_udate();
  if (udate_ == &::google::protobuf::internal::kEmptyString) {
    udate_ = new ::std::string;
  }
  udate_->assign(value);
}
inline void idea_info::set_udate(const char* value) {
  set_has_udate();
  if (udate_ == &::google::protobuf::internal::kEmptyString) {
    udate_ = new ::std::string;
  }
  udate_->assign(value);
}
inline void idea_info::set_udate(const void* value, size_t size) {
  set_has_udate();
  if (udate_ == &::google::protobuf::internal::kEmptyString) {
    udate_ = new ::std::string;
  }
  udate_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* idea_info::mutable_udate() {
  set_has_udate();
  if (udate_ == &::google::protobuf::internal::kEmptyString) {
    udate_ = new ::std::string;
  }
  return udate_;
}
inline ::std::string* idea_info::release_udate() {
  clear_has_udate();
  if (udate_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = udate_;
    udate_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace rtb
}  // namespace ad

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_idea_5finfo_2eproto__INCLUDED
