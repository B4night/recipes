# combination

此程序的作用是在values数组中找到任意三个元素的组合.

实现方法: 使用一个大小和values一样大的数组selector, 其值为`'1, 1, 1, 0, 0, 0, 0'`. 元素1的作用是选取values中对应的元素, 元素0是不选. 使用`prev_permutation`得到selector的各种排序. 

由于values不变, 变的只是selector, 即变的只是选取values数组元素的规则.

``` C++
for (size_t i = 0; i < selectors.size(); ++i)
{
    if (selectors[i])
    {
        std::cout << values[i] << ", ";
    }
}
```



`prev_permutation`和`next_permutation`类似, 下面讲解`next_permutation`函数:

对数组arr调用`next_permutation`, 若存在下一个排序, 则arr会变成下一个排序. 否则返回false, arr变为最大字典序

下一个排序: 按字典序比arr大的排序中字典序最小的排序

注意: 调用`next_permutation`时, 应该确保此时arr的字典序是最小的, 否则结果不会是arr的全排序.



# iprange

此程序的作用: 有多个IP range, 每个range中都有一个value. 现在给出ip, 求它在哪一个range中, 并得到它的range.

``` C++
int findIpValue(const std::vector<IPrange>& ranges, uint32_t ip)	
    // 根据ip的值,找到对应range,返回该range的值
{
  int result = -1;

  if (!ranges.empty()) {
    IPrange needle = { ip, 0, 0 };
    std::vector<IPrange>::const_iterator it
        = std::lower_bound(ranges.begin(), ranges.end(), needle); 
      // 找到[begin,end]中第一个>=needle的元素
      // 即找到第一个range,range的startIP > ip
    if (it == ranges.end()) {
      --it;	
        // 此时说明ranges中每一个元素的startIP都小于ip,只要比较ranges中最后一个range是否包含ip
        //由于it指向最后一个range后一个元素,需要将it-1
    } else if (it != ranges.begin() && it->startIp > ip) {	
        //此时说明it指向的range的startIP大于ip,则需要查询it前面一个range是否包含ip即可
      --it;
    }

    if (it->startIp <= ip && it->endIp >= ip) {
      result = it->value;	// 判断it指向的range是否包含ip
    }
  }

  return result;
}
```



`adjacent_find`函数:

>  Return value: An iterator to the first of the first pair of identical elements.

即对数组`{1, 2, 3, 4, 4, 5, 6...}`调用`adjacent_find(arr.begin(), arr.end())`, 返回的是指向数组中第一个元素`4`的迭代器.

如果数组中没有符合要求的元素, 会返回`arr.end()`, 即第二个参数



`lower_bound`函数:

``` C++
template< class ForwardIt, class T >
ForwardIt lower_bound( ForwardIt first, ForwardIt last, const T& value );
```

> Returns an iterator pointing to the first element in the range `[first, last)` that does not satisfy element < value (or comp(element, value)), (i.e. greater or equal to), or `last` if no such element is found.

即返回指向`[first,last]`中第一个`>=value`的元素的迭代器