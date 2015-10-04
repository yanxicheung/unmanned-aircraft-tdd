#ifndef SFJDLLSDFLKSAF_LJSFDLSKFDLNV_CXHKJ
#define SFJDLLSDFLKSAF_LJSFDLSKFDLNV_CXHKJ


/////////////////////////////////////////////////////////////////////////////
#define ROLE(role) get##role()
#define ROLE_PROTO_TYPE(role) role& ROLE(role) const
#define USE_ROLE(role) virtual ROLE_PROTO_TYPE(role) = 0
#define HAS_ROLE(role) USE_ROLE(role)
#define DECL_ROLE(role) ROLE_PROTO_TYPE(role)
//////////////////////////////////////////////////////////////////
#define IMPL_ROLE(role)                                       \
ROLE_PROTO_TYPE(role)                                         \
{                                                             \
   return const_cast<role&>(static_cast<const role&>(*this)); \
}

/////////////////////////////////////////////////////////////////////////////
namespace details
{
   struct Role
   {
      virtual ~Role() {}
   };
}

#define DEFINE_ROLE(role)  struct role : ::details::Role

#endif
