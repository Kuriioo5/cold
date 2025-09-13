#ifndef PLATFORM_H
#define PLATFORM_H

typedef enum 
{
  PLATFORM_UNSUPPORTED = 0,
  PLATFORM_WINDOWS,
  PLATFORM_LINUX
} Platform;

Platform get_platform(void) 
{
#if defined(_WIN32) || defined(_WIN64)
  return PLATFORM_WINDOWS;
#elif defined(__linux__)
  return PLATFORM_LINUX;
#else
  returen PLATFORM_UNSUPPORTED
#endif
}

#endif
