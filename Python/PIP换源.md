1.临时换源：

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```
 #清华源
pip install markdown -i https://pypi.tuna.tsinghua.edu.cn/simple
# 阿里源
pip install markdown -i https://mirrors.aliyun.com/pypi/simple/
# 腾讯源
pip install markdown -i http://mirrors.cloud.tencent.com/pypi/simple
# 豆瓣源
pip install markdown -i http://pypi.douban.com/simple/
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

2.永久换源：

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```
# 清华源
pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple
# 阿里源
pip config set global.index-url https://mirrors.aliyun.com/pypi/simple/
# 腾讯源
pip config set global.index-url http://mirrors.cloud.tencent.com/pypi/simple
# 豆瓣源
pip config set global.index-url http://pypi.douban.com/simple/# 换回默认源pip config unset global.index-url
```