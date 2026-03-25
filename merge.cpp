#include <cstddef>

template<class T>
T * merge(const T * const * a, size_t sa, const size_t * sai, T * c)
{
  size_t * index = nullptr;
  try
  {
    index = new size_t[sa]{0};
  }
  catch (...)
  {
    throw std::bad_alloc();
  }
 
  size_t count = 0;
  for (size_t i = 0; i < sa; i++)
  {
    count += sai[i];
  }

  for (size_t k = 0; k < count; k++)
  {
    size_t counter = 0;
    for (size_t i = 0; i < sa; i++)
    {
      if (index[i] < sai[i])
      {
        counter++;
      }
    }
    if (!counter)
    {
      break;
    }
    T * temp = nullptr;
    try
    {
      temp = new T[counter];
    }
    catch (...)
    {
      delete [] index;
      throw std::bad_alloc();
    }
    size_t id = 0;
    for(size_t i = 0; i < sa; i++)
    {
      if (index[i] < sai[i])
      {
        try
        {
          temp[id] = a[i][index[i]];
        }
        catch (...)
        {
          delete [] temp;
          delete [] index;
          throw;
        }
        id++;
     }
   }
   T min;
   try
   {
     min = temp[0];
   }
   catch (...)
   {
     delete [] index;
     delete [] temp;
     throw;
   }
   for (size_t i = 1; i < counter; i++)
   {
     if (temp[i] < min)
     {
        try
        {
          min = temp[i];
        }
        catch (...)
        { 
          delete [] index;
          delete [] temp;
          throw;
        }
      }
    }
    for(size_t i = 0; i < sa; i++)
    {
      if (index[i] < sai[i])
      {
        try
        {
          if (min == a[i][index[i]])
          {
            index[i]++;
            break;
          }
        }
        catch (...)
        {
          delete [] index;
          delete [] temp;
          throw;
        }
      }
    }
    delete [] temp;
    try
    {
      c[k] = min;
    }
    catch (...)
    {
       delete [] index;
       throw;
    }
  }
  delete [] index;
  return c;
}
