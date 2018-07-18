### 有道云笔记 markdown模板

[toc] 

<font size=4></font>

抽空把[【简明版】有道云笔记Markdown指南](http://note.youdao.com/iyoudao/?p=2411)的图片版欢迎成了Markdown~



![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/758x240-2.jpg)

什么是Markdown？Markdown是一种轻量级的「标记语言」，通常为程序员群体所用，目前它已是全球最大的技术分享网站 GitHub 和技术问答网站 StackOverFlow 的御用书写格式。

**有道云笔记内置Markdown编辑器和使用指南，非技术类笔记用户，千万不要被「标记」、「语言」吓到，Markdown的语法十分简单，常用的标记符号不超过十个，用于日常写作记录绰绰有余，不到半小时就能完全掌握。**

就是这十个不到的标记符号，却能让人**优雅地沉浸式记录，专注内容而不是纠结排版**，达到「心中无尘，码字入神」的境界。

# 一、利用Markdown可以做什么？

1. 代码高亮

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/1-1%E4%BB%A3%E7%A0%81%E9%AB%98%E4%BA%AE.png)

### 代码高亮

```python

@requires_authorization

def somefunc(param1='', param2=0):

'''A docstring'''

if param1 > param2: # interesting

print 'Greater'

return (param2-param1+1) or None

Class SomeClass:

pass

>>> message = '''interpreter

... prompt'''

```

2. 制作待办事项To-do List

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/1-2%E5%BE%85%E5%8A%9E%E4%BA%8B%E9%A1%B9.png)

### To-do List

- [x] 已完成项目1

- [x] 已完成事项1

- [x] 已完成事项2

- [ ] 待办事项1

- [ ] 待办事项2

3. 高效绘制 流程图、序列图、甘特图、表格

### 流程图：

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/%E6%B5%81%E7%A8%8B%E5%9B%BE.png)

```

graph TD

A[christmas] -->B(Go shopping)

B --> C{LEt me think}

C -->|One| D[Laptop]

C -->|Two| E[iPhone]

C -->|Three|F[Car]

```

### 序列图：

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/%E5%BA%8F%E5%88%97%E5%9B%BE.png)

```

sequenceDiagram

loop every day

Alice->>John: Hello John, how are you?

John-->> Alice: Great!

end

```

### 甘特图：

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/%E7%94%98%E7%89%B9%E5%9B%BE.png)

```

gantt

dateFormat YYYY-MM-DD

title 产品计划表

section 初期阶段

明确需求: 2016-03-01, 10d

section 中期阶段

跟进开发: 2016-03-11, 15d

section 后期阶段

走查测试: 2016-03-20, 9d

```

**==tips==: 以上流程图均为半角标点**

### 表格：

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/1-3%E8%A1%A8%E6%A0%BC.png)

### 表格

|Item | Value | Qty |

|:------    |---------:    |:--:  |

|Computer  |  1600 USD    |  5  |

|Phone      |  12 USD      |  12  |

|Pipe      |  12 USD      |  234  |

4. 书写数学公式

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/%E6%95%B0%E5%AD%A6%E5%85%AC%E5%BC%8F.png)

## Mathematical formula `$y = x^2$`

Inline math: `$\dfrac{\tfrac{1}{2}[1-(\tfrac{1}{2})^n]}{1 - \tfrac{1}{2}} = s_n$`

Math block:

```math

\oint_C x^3\, dx+4y^2\,dy

2 = \left(\frac{\left(3-x\right)\times 2}{3-x}\right)

\sum_{m=1}^\infty\sum_{n=1}^\infty\frac{m^2n}{3^m\left(m3^n+n3^m\right)}

\phi_n(\kappa) = \frac{1}{4\pi^2\kappa^2}\int_0^\infty\frac{\sin(\kappa R)}{\kappa R}\frac{\partial}{\partial R}\left[R^2\frac{\partial D_n(R)}{\partial R}\right]dR

```

# 二、有道云笔记Markdown简明版使用指南

**0. 标题**

标题是每篇文章必备而且最常用的格式。

在Markdown中，如果想将一段文字定义为标题，只需要在这段文字前面加上 #，再在 # 后加一个空格即可。还可增加二、三、四、五、六级标题，总共六级，只需要增加 # ，增加一个 # ，标题字号相应降低一级。如图：

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/2-0-%E6%A0%87%E9%A2%98.png)

# 一级标题

## 二级标题

### 三级标题

#### 四级标题

**1. 列表**

列表格式也很常用，它可以让你的文稿变得井井有条。在 Markdown 中，你只需要在文字前面加上 - 就可以了；如果你希望是有序列表，在文字前面加上 1. 2. 3. 即可

#### 无序列表

- 列表1

- 列表1.1

- 列表1.2

- 列表2

- 列表3

-

#### 有序列表

1. 列表1

1. 列表1.1

2. 列表1.2

2. 列表2

3. 列表3

**2. 引用**

如果你需要在文稿中引用一段别处的句子，那么就要用到「引用」格式。

在引用文字前加上 > 并与文字保留一个字符的空格，即可。

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/2-2%E5%BC%95%E7%94%A8.png)

######引用

> 记录， 成为更好的自己。————有道云笔记

**3. 粗体和斜体**

Markdown 的粗体和斜体也非常简单：

用两个 * 包含一段文本就是粗体的语法；

用一个 * 包含一段文本就是斜体的语法。

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/2-3-%E7%B2%97%E4%BD%93%E6%96%9C%E4%BD%93.png)

*这是斜体*

**这是粗体**

#### 注意： 符号与文本之间无需空格

**4. 链接和图片**

```

链接：在 Markdown 中，插入链接只需要使用 [显示文本](链接地址) 即可。

图片：在 Markdown 中，插入图片只需要使用 ![显示文本](图片链接地址)即可。

```

注：插入图片的语法和链接的语法很像，只是前面多了一个 ！

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/2-4%E9%93%BE%E6%8E%A5%E4%B8%8E%E5%9B%BE%E7%89%87.png)

#### 插入链接

[有道云笔记官网](http://note.youdao.com/)

#### 插入图片

![有道云笔记](http://note.youdao.com/favicon.ico)

**5. 分割线**

分割线的语法只需要另起一行，连续输入三个星号 *** 即可分割两段文字内容。

如图：

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/2-5-%E5%88%86%E5%89%B2%E7%BA%BF.png)

#### 分割线

这是第一段内容

***

这是第二段内容

**6. 表格**

当你需要在Markdown文稿中键入表格，代码如下：

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/2-6%E8%A1%A8%E6%A0%BC.png)

示例参考：

### 表格

|Item | Value | Qty |

|:------    |---------:    |:--:  |

|Computer  |  1600 USD    |  5  |

|Phone      |  12 USD      |  12  |

|Pipe      |  12 USD      |  234  |

**如上7大格式是写作文稿时最常使用的。**

怎么样，看了相关Markdown语法是不是觉得挺简单？

当然，Markdown新手在使用不熟练的情况下，可能会忘记相关语法，也没关系，笔记的工具栏内置了Markdown语法，方便学习与熟悉。

如，「表格」语法相对复杂，你可能忘记了，这时候，你只需要点击编辑框上方工具栏，点选「表格」的图标，左边编辑区便会出现「表格」相应代码：

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/2-6%E8%A1%A8%E6%A0%BC-3.jpg)

然后，你只需要将代码替换成相应文本即可，如图：

![](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/1-3%E8%A1%A8%E6%A0%BC1.png)

熟悉语法之后，还是建议大家少使用辅助工具栏，尽量自己键入代码，感受纯文本之美。

当然，有道云笔记的Markdown还能支持制作待办事项，书写流程图、序列图、甘特图，书写数学公式等，是不是够极客，够有逼格？

看看笔记菌用Markdown甘特图写的项目计划时间表：

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/2-6-8.png)

## Tips for 有道云笔记中的 Markdown

**① 实时同步预览，所看即所得**

我们将笔记编辑界面一分为二，左边为编辑区，右边为预览区，两区滚动条同步。在编辑区的操作能够实时反映在预览区，方便及时调整和查看最终版面效果。

**② 工具栏内置Markdown语法，方便新手学习**

编辑页面顶端的工具栏有对应代码，如果你是一个不熟悉Markdown语法的新手，可以先尝试用工具栏辅助操作。也可以在网上搜索「Markdown语法指南」进行学习。

当然，如果你觉得工具栏太打扰，点击下方分界条即可隐藏工具栏，切换到极简编辑环境。

**③ 实时云端保存**

Markdown模式继承了有道云笔记的优良传统，你每一次击键的内容都会实时保存在云端，无需担心浏览器崩溃、设备没电、突然断网等情况。对于写作者来说，更是再也不用担心因为各种原因痛失文稿的情况了。

**④ 界面大小可点击分界条调整。**

点击“1”处，工具栏收起；

点击“2”处，右侧预览区收起。

![image](http://note.youdao.com/iyoudao/wp-content/uploads/2016/09/91.jpg)


## 在有道云笔记 - Markdown模式下的显示效果:
<http://note.youdao.com/noteshare?id=6ec3c87769048bf2ba7df068f377e5a3&sub=131D97485A5E4AE5A1E2CBC0CF3E679C>
