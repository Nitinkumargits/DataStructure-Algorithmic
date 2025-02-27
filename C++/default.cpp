Here’s the **Merge Sort **implementation in both **Java **and **JavaScript ** :

    -- -

    ##**Java Implementation **
```java
        import java.util.Arrays;

public
class MergeSort
{
public
    static void merge(int[] arr, int low, int mid, int high)
    {
        int[] temp = new int[high - low + 1];
        int left = low, right = mid + 1, k = 0;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp[k++] = arr[left++];
            }
            else
            {
                temp[k++] = arr[right++];
            }
        }

        while (left <= mid)
        {
            temp[k++] = arr[left++];
        }

        while (right <= high)
        {
            temp[k++] = arr[right++];
        }

        System.arraycopy(temp, 0, arr, low, temp.length);
    }

public
    static void mergeSort(int[] arr, int low, int high)
    {
        if (low >= high)
            return;

        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

public
    static void main(String[] args)
    {
        int[] arr = {3, 1, 2, 4, 5, 6, 2, 4};
        mergeSort(arr, 0, arr.length - 1);

        System.out.println(Arrays.toString(arr)); // Output: [1, 2, 2, 3, 4, 4, 5, 6]
    }
}
```
### **Explanation**
- **Recursive `mergeSort()`**: Splits the array into halves until each part has one element.
- **`merge()` function**: Merges two sorted halves into a single sorted array.
- Uses **`System.arraycopy`** for efficient copying.

---

## **JavaScript Implementation**
```javascript
function merge(arr, low, mid, high)
{
    let temp = [];
    let left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push(arr[left++]);
        }
        else
        {
            temp.push(arr[right++]);
        }
    }

    while (left <= mid)
    {
        temp.push(arr[left++]);
    }
    while (right <= high)
    {
        temp.push(arr[right++]);
    }

    for (let i = 0; i < temp.length; i++)
    {
        arr[low + i] = temp[i];
    }
}

function mergeSort(arr, low, high)
{
    if (low >= high)
        return;

    let mid = Math.floor((low + high) / 2);
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

// Example Usage
let arr = [ 3, 1, 2, 4, 5, 6, 2, 4 ];
mergeSort(arr, 0, arr.length - 1);
console.log(arr); // Output: [1, 2, 2, 3, 4, 4, 5, 6]
```

### **Explanation**
- **Recursive `mergeSort()`**: Splits the array until it reaches single elements.
- **`merge()` function**: Merges sorted subarrays into a larger sorted array.
- Uses **JavaScript arrays (`temp.push()`)** instead of `System.arraycopy`.

---

### **Output for Both Java & JavaScript**
```
[1, 2, 2, 3, 4, 4, 5, 6]
```
Both versions successfully implement **Merge Sort** with **O(N log N) time complexity**. 🚀