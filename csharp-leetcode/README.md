# Leetcode 刷题方法及AC 代码 - C#版

## 使用VS code刷题及如何快速配置C#运行环境

十分推荐使用C# script的环境来刷题，这样就不用每次都去创建项目了，只需要在一开始配置一次即可一劳永逸。

[scriptcs](http://scriptcs.net)开源项目的作者 Filip W 大佬的 dotnet-script 是基于微软的 roslyn 及其推出的 csx 开发的，其 debug 功能是与 微软官方的vs code 的 C# 插件 (Omnisharp) 相适配的，OmiSharp插件天然支持 intellisence，整体上很不错的。不需要创建 project 就能编译、运行、debug以及加 unit test并debug unit test. 不需写任何多余的代码。


### 前期准备:
安装 .NET core SDK (版本在2.0以上)、VS code、VS code 的 C# 插件


### 配置步骤:


### 1、全局安装 dotnet-script 
打开cmd，执行如下命令:
```bash
dotnet tool install -g dotnet-script
```


### 2、在 vs code 中安装 scriptcs runner 插件

[https://marketplace.visualstudio.com/items?itemName=filipw.scriptcsRunner](https://marketplace.visualstudio.com/items?itemName=filipw.scriptcsRunner)
安装好后，Windows上可以用 Ctrl+shift+r 快捷键运行整个 csx 文件或其中某一个选择的snippet。

Ctrl + F5: 运行
F5: 调试

### 3、在需要存放项目文件的文件夹中打开vs code 并进行一次性地初始化项目
打开需要存放项目文件的文件夹，右击 Open with code，在 VS code的 Terminal 中输入如下命令:
```bash
dotnet script init
```

或 
```bash
dotnet script init leetcode1
```


会自动生成 .vscode/launch.json 文件和 omnisharp.json 文件，后面不需要动的，当然你甚至可以在vs code中设置为不显示在文件列表中。




### 4、为 vs code 安装 C# 代码格式化插件

**1**: 从repo [https://github.com/yanglr/DevToolsBackup/tree/main/vs%20code](https://github.com/yanglr/DevToolsBackup/tree/main/vs%20code) 下载 C# fixformat 的 vsix 安装包

**2**: 打开 vsix 所在文件夹，然后用如下命令进行安装:

```bash
code --install-extension ./csharp-fixformat-0.0.84.vsix
```

**3**: 打开任一个  `.cs`  文件, 然后按 F1， 键入"Format document with...", 将 "C# FixFormat" 设置为默认格式化工具

**4**: 接下来你就可以用快捷键 `Ctrl + K + F` 来格式化 C# 代码了.



### 5、注意事项

我们所操作的文件目录(比如，这里的 D:\coding\2021\csxLeetcode )支持放 .cs 和 .csx 文件。
csx 文件中不能加 namespace、public static void Main()。
using System; 这种语句会默认自动导入，也可省略。




### 6、此环境下 Leetcode的玩法


#### 不带 class 的 leetcode 玩法
leetcode-demo.csx


```csharp
using System;
using System.Text;

public class Solution {
    public int Add (int a, int b) {
        return a + b;
    }
}

public void Main () {
    var sol = new Solution ();
    Console.WriteLine (sol.Add (8, 5));
}

Main ();
```



#### 带 class 和 基于Nunit 的 Unit test 的 leetcode 玩法

nunit-test.csx
```csharp
#r "nuget: NUnit, 3.12.0"
#r "nuget: NUnitLite, 3.12.0"
using NUnit.Framework;
using NUnitLite;

public class MyTests {
    [Test]
    public void Test()
    {
        Assert.IsTrue(true);
    }
}
new AutoRun().Execute (Args.ToArray ());
```


此处 unit test的debug方法是:

- 加断点
- 按F5



这里 codelen 上的 Run Test/Debug Test 都是无效的，就别点了。


如果按F5, 断点无法hit，那么可以清空当前文件夹中的 TestResult.xml，或者用一个 Assert 会失败的任意 Test 去实现debug中hit断点，再按F5 (continue) 时进入目标断点~



对于 Leetcode，如果需要加入可调试的 unit tests，可以这样玩:
nunit-test2.csx

```csharp
#r "nuget: NUnit, 3.12.0"
#r "nuget: NUnitLite, 3.12.0"
using NUnit.Framework;
using NUnitLite;

public class Solution {
    public int Add(int a, int b) {
        return a + b;
    }

    [Test]
    public void Test() {
        Assert.AreEqual (23, this.Add(8, 15));
    }
}

new AutoRun().Execute(Args.ToArray());
```



### 相关repo:

ilipw/dotnet-script: Run C# scripts from the .NET CLI - Filip W
[https://github.com/filipw/dotnet-script](https://github.com/filipw/dotnet-script)


Experimenting with dotnet scripts
From <[https://blog.schroederspace.com/tumbleweed-technology/experimenting-with-dotnet-scripts](https://blog.schroederspace.com/tumbleweed-technology/experimenting-with-dotnet-scripts)>


nunit-scripts.csx
[https://gist.github.com/jpschroeder/635ec6677d36805cee02adee702b4d47](https://gist.github.com/jpschroeder/635ec6677d36805cee02adee702b4d47)


[mono](https://github.com/mono)/[roslyn](https://github.com/mono/roslyn)
[https://github.com/mono/roslyn/blob/master/src/Scripting/CSharpTest/ScriptTests.cs](https://github.com/mono/roslyn/blob/master/src/Scripting/CSharpTest/ScriptTests.cs)
