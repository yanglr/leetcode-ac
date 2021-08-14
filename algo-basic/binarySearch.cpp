bool check(int x) // 检查x是否满足某种性质
{ 
    /* ...*/
}

// 区间[1, r]被划分成[1, mid]和[mid + 1, r]时使用:
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}

// 区间[1, r]被划分成[1, mid - 1]和[mid, r]时使用:
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else r = mid - 1;
    }
    return l;
}
