#ifndef CLICK_ABCAddress_HH
#define CLICK_ABCAddress_HH
#include <click/string.hh>
#include <iostream>
#include <click/glue.hh>
#include <clicknet/abc.h>
CLICK_DECLS
class StringAccum;
template <typename T> class Vector;

class ABCAddress {

  public:


    inline ABCAddress()
	: _addr(0) {
    }

    inline ABCAddress(uint64_t  x)
	: _addr(x) {
    }

    explicit ABCAddress(const unsigned char *data) {
	#if HAVE_INDIFFERENT_ALIGNMENT
		_addr = *(reinterpret_cast<const unsigned *>(data));
	#else
		memcpy(&_addr, data, 8);
	#endif
    }

    inline bool empty() const {
	return !_addr;
    }

    inline uint64_t addr() const {
	return _addr;
    }

    inline operator uint64_t() const {
	return _addr;
    }

    inline unsigned char* data();

    inline bool matches_prefix(ABCAddress addr) const;

  private:

    uint64_t _addr;

};


inline bool
ABCAddress::matches_prefix(ABCAddress addr) const
{
    // >>48bit for ignore mac ,due to  PSPaddresss = subnet + mac
    return (((this->addr()>>48) ^ addr.addr()) == 0);
}


inline bool
operator==(ABCAddress a, ABCAddress b)
{
    return a.addr() == b.addr();
}

inline bool
operator==(ABCAddress a, uint64_t b)
{
    return a.addr() == b;
}

inline bool
operator!=(ABCAddress a, ABCAddress b)
{
    return a.addr() != b.addr();
}

inline bool
operator!=(ABCAddress a, uint64_t b)
{
    return a.addr() != b;
}

inline ABCAddress
operator&(ABCAddress a, ABCAddress b)
{
    return ABCAddress(a.addr() & b.addr());
}

inline ABCAddress
operator^(ABCAddress a, ABCAddress b)
{
    return ABCAddress(a.addr() ^ b.addr());
}

inline unsigned char*
ABCAddress::data()
{
    return reinterpret_cast<unsigned char*>(&_addr);
}


StringAccum& operator<<(StringAccum&, ABCAddress);


CLICK_ENDDECLS
#endif
