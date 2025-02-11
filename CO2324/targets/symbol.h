#ifndef __TIL_TARGETS_SYMBOL_H__
#define __TIL_TARGETS_SYMBOL_H__

#include <string>
#include <memory>
#include <cdk/types/basic_type.h>

namespace til {

  class symbol {
    std::string _name;
    std::shared_ptr<cdk::basic_type> _type;
    int _qualifier;
    int _offset = 0;
    long _value; // hack!
    bool _is_main = false;

  public:
    symbol(const std::string &name, std::shared_ptr<cdk::basic_type> type, int qualifier) :
        _name(name), _type(type), _qualifier(qualifier) {
    }

    virtual ~symbol() {
      // EMPTY
    }

    std::shared_ptr<cdk::basic_type> type() const {
      return _type;
    }
    bool is_typed(cdk::typename_type name) const {
      return _type->name() == name;
    }
    const std::string &name() const {
      return _name;
    }
    int offset() const {
      return _offset;
    }
    int offset (int v) {
      return _offset = v;
    }
    int qualifier() const {
      return _qualifier;
    }
    long value() const {
      return _value;
    }
    long value(long v) {
      return _value = v;
    }
    const std::string& identifier() const {
          return name();
    }
    bool global() const {
      return _offset == 0;
    }
    bool is_main() const {
      return _is_main;
    }
    bool is_main(bool v) {
      return _is_main = v;
    }
  };

  inline auto make_symbol(const std::string &name, std::shared_ptr<cdk::basic_type> type, int qualifier = 0) {
    return std::make_shared<symbol>(name, type, qualifier);
  }

} // til

#endif
