#pragma once
#include <mini/ptr.h>
#include <mini/common.h>

#include <windows.h>
#include <wincrypt.h>

namespace mini::crypto {

class aes;
class sha1;
class dh1024;
class rsa;
class random;

class provider
{
  public:
    MINI_MAKE_NONCOPYABLE(provider);

    provider(
      void
      );

    ~provider(
      void
      );

    void
    init(
      void
      );

    void
    destroy(
      void
      );

    HCRYPTPROV
    get_handle(
      void
      );

    HCRYPTPROV
    get_dh_handle(
      void
      );

    ptr<aes>
    create_aes(
      void
      );

    ptr<sha1>
    create_sha1(
      void
      );

    ptr<dh1024>
    create_dh1024(
      void
      );

    ptr<rsa>
    create_rsa(
      void
      );

    ptr<random>
    create_random(
      void
      );

  private:
    HCRYPTPROV _provider_handle;
    HCRYPTPROV _dh_provider_handle;
};

extern provider provider_factory;

}
