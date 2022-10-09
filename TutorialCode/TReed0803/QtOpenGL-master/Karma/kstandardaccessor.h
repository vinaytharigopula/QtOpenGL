#ifndef KSTANDARDACCESSOR_H
#define KSTANDARDACCESSOR_H KStandardAccessor

#include <KAccessor>

template <typename T>
class KStandardAccessor : public KAccessor<T, T>
{
public:
  typedef typename KAccessor<T, T>::ReturnType ReturnType;
  typedef typename KAccessor<T, T>::ContainedType ContainedType;
  ReturnType const &operator()(ContainedType const &elm) const;
};

template <typename T>
auto KStandardAccessor<T>::operator()(ContainedType const &elm) const -> ReturnType const &
{
  return elm;
}

#endif // KSTANDARDACCESSOR_H

