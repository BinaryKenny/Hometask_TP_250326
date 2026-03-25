template<class T>
T * merge(const T * const * a, size_t sa, const size_t * sai, T * c)
{
  index = new size_t[sa]{0}; 		//возможно исключение из-за new
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
   temp = new T[counter];	//опять же возможно исключение из-за new
   size_t id = 0;
   for(size_t i = 0; i < sa; i++)
   {
     if (index[i] < sai[i])
     {
       temp[id] = a[i][index[i]]; //копирование объекта типа T может выбросить исключение
       id++;
     }
   }
   T min = temp[0];		//копирование, возмонжно исключение
   for (size_t i = 1; i < counter; i++)
   {
     if (temp[i] < min)
     {
        min = temp[i];	//возможно исключение из-за копирования
     }
   }
   for(size_t i = 0; i < sa; i++)
   {
      if (index[i] < sai[i])
      {
        if (min == a[i][index[i]]) // возможно исключения из-за operator== для класса T
        {
          index[i]++;
          break;
        }
      }
    }
    delete [] temp;
    c[k] = min;    // исключение из-за копирования
  }
  delete [] index;
  return c;
}
