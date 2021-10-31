#ifndef HEDRALCOREMACROS_HPP
#define HEDRALCOREMACROS_HPP

#define HEDRAL_DECLARE_INTERFACE(interf, iid) virtual ~interf(); \
        static INTERFACEID IID(){ return iid; }

#define HEDRAL_IMPLEMENT_INTERFACE(interf) interf::~interf() {}

#define HEDRAL_DECLARE_CLASSFACTORY(F, I) \
struct F\
{\
    static Hedral::Core::ComPtr<I> CreateInstance(); \
};

#define HEDRAL_IMPLEMENT_CLASSFACTORY(F, IMPL, I) \
Hedral::Core::ComPtr<I> F::CreateInstance()\
{\
    I* p = new (std::nothrow)IMPL();\
    if(p != nullptr) \
        return Hedral::Core::ComPtr<I>(p);\
    throw std::bad_exception();\
}

#define HEDRAL_DEPENDENCY(TYPE, NAME, NAMESPACE, DEPENDENCY) \
    protected: TYPE NAME = Hedral::NAMESPACE::Global##DEPENDENCY::Instance();

#endif
