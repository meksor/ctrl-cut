
#ifndef VIEWS_H_
#define VIEWS_H_

#include "Iterators.hpp"
#include <boost/range/iterator_range.hpp>

template<
  typename Titer,
  typename TparentIter
>
struct View : boost::iterator_range<Titer> {
public:
  typedef boost::iterator_range<Titer> _Base;
  typedef Titer iterator;

  View(TparentIter begin, TparentIter end) : _Base(Titer(begin, end), Titer(end, end)) {}

  typename Titer::reference front() {
    return *Titer(_Base::begin(), _Base::begin()+1);
  }
  typename Titer::reference back() {
    return *Titer(_Base::end()-1, _Base::end());
  }

  bool empty() const { //FIXME specialize
    return this->size() == 0;
  }

  size_t size() const {  //FIXME specialize
    int num = 0;
    for(iterator it = this->begin(); it != this->end(); it++)
      num++;
    return num;
  }
};

template<typename TpointRange>
struct SegmentView :
  public View<
    SegmentWiseIterator<typename TpointRange::const_iterator>,
    typename TpointRange::const_iterator
  > {
  SegmentView(TpointRange& points) :
    View<
        SegmentWiseIterator<typename TpointRange::const_iterator>,
        typename TpointRange::const_iterator
    >(points.begin(),points.end())
  {}

  SegmentView(typename TpointRange::const_iterator begin, typename TpointRange::const_iterator end) :
    View<
        SegmentWiseIterator<typename TpointRange::const_iterator>,
        typename TpointRange::const_iterator
    >(begin,end)
  {}
};


template<typename TmultiPointRange>
struct MultiPointView :
  public View<
    MultiIter<typename TmultiPointRange::const_iterator>,
    typename TmultiPointRange::const_iterator
  >
{
  typedef View<MultiIter<typename TmultiPointRange::const_iterator>,typename TmultiPointRange::const_iterator > _Base;

  MultiPointView(TmultiPointRange mpr) :
    _Base(mpr.begin(),mpr.end())
  {}
  MultiPointView(typename TmultiPointRange::const_iterator begin, typename TmultiPointRange::const_iterator end) :
    _Base(begin,end)
  {};
};


template<typename TmultiPointRange>
struct MultiSegmentView :
  public View<
           MultSegmentWiseIterator<typename TmultiPointRange::const_iterator>,
           typename TmultiPointRange::const_iterator
         >
{
  typedef View<
      MultSegmentWiseIterator<typename TmultiPointRange::const_iterator>,
      typename TmultiPointRange::const_iterator
    > _Base;

  MultiSegmentView(TmultiPointRange& r) :
    _Base(r.begin(), r.end())
  {};
};

#endif /* VIEWS_H_ */
