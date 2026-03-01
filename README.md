![Phobos YR Engine Extension](logo.png)

[![Github All Releases](https://img.shields.io/github/downloads/Phobos-developers/Phobos/total.svg)](https://github.com/Phobos-developers/Phobos/releases)
[![Docs status](https://readthedocs.org/projects/phobos/badge/?version=latest)](https://phobos.readthedocs.io/en/latest/?badge=latest)
[![Workflow](https://img.shields.io/github/actions/workflow/status/Phobos-developers/Phobos/nightly.yml?branch=develop)](https://github.com/Phobos-developers/Phobos/actions)
[![EditorConfig](https://github.com/Phobos-developers/Phobos/workflows/EditorConfig/badge.svg)](https://github.com/Phobos-developers/Phobos/actions?query=workflow%3AEditorConfig)
[![license](https://img.shields.io/github/license/Phobos-developers/Phobos.svg)](https://www.gnu.org/licenses/lgpl-3.0.en.html)

项目目前的维护工作不够积极，因此我们正在寻找积极的维护者。

请在 [Discord 频道](https://discord.gg/sZeMzz6qVg)留言给我们 （或直接私信 Kerbiter）。

# Phobos

...是一个社区引擎扩展项目，基于 [自定义 YRpp](https://github.com/Metadorius/YRpp) 与 [Syringe](https://github.com/Ares-Developers/Syringe) 为《尤里的复仇》提供一系列新功能和修复。它旨在与 [Ares](https://github.com/Ares-Developers/Ares) 引擎配套使用，而非取而代之，因此不会带来不兼容问题。

虽然 Phobos 独立于 Ares 并且不需要 Ares 即可运行，但 Phobos 补充了 Ares 的一些功能，反之亦然。

此产品不受 EA 官方认可及支持。

社区
---------

由于这是一个国际性的项目而英语是目前最常用的第二语言，因此英语是该项目的主要语言。 不过我们知道很多人的英语可能不如母语那样好，而且／或者在访问 Discord 时可能会遇到困难，所以我们并不限制创建特定语言的社区群组。

- **[🌐国际性的 Discord 频道：C&C Mod Haven](https://discord.gg/sZeMzz6qVg)**
- **[🇨🇳 中文社区公共交流论坛：Phobos CN](https://phoboscn.top)**

下载
---------

你可以选择下列方式：
- [最新的稳定发布版本](https://github.com/Phobos-developers/Phobos/releases/latest) （Bug 最少的版本，但功能更新上非常缓慢）
- [最新的开发分支版本](https://github.com/Phobos-developers/Phobos/releases) （Bug 相对较少的版本，开发构建会在新功能**完成后**立即更新）
- [最新的每夜构建版本](https://nightly.link/Phobos-developers/Phobos/blob/develop/.github/workflows/nightly.yml)（添加了尚未发布的功能，这些功能将在下一个开发分支版本中推出）
- 用于测试单个新功能的每夜构建可在 [拉取请求](https://github.com/Phobos-developers/Phobos/pulls) 中找到

### 关于每夜构建版本的说明

后两个版本是前瞻版本（不要在测试之外重新分发它们！）

并且它们会在游戏中显示无法关闭的版本构建信息（提交和分支／标签）。

你可以通过开发分支（上方链接）获取一个构建版本以及在拉取请求中通过自动化机器人的评论获取其开发分支上任何最新成功编译的 Phobos 版本。

注意**只有当拉取请求没有合并冲突**时才会生成。

此外，你可以手动运行 GitHub Actions 来获取一个由工作流自动生成的工件。

只需要点击绿色勾号，打开工作流页面，找到并下载对应的工件。

这仅限于被授权的用户执行。

安装和使用
----------------------

0. 如果您的 mod 中还没有安装 Syringe，可以连同 [最新版 Ares 软件包](https://launchpad.net/ares/+download) 一同下载。安装时，只需将 `Syringe.exe` 拖入游戏根目录（即您的 `gamemd.exe` 所在的位置）。强烈建议同时**安装 Ares** 以获得完整的 Phobos 功能体验，只需将压缩包中除 Documentation 目录之外的所有文件放入游戏根目录即可。
1. 获取 Phobos 「软件包」（可在 [发布页面](https://github.com/Phobos-developers/Phobos/releases) 找到官方构建版；阅读下文了解如何获取每夜构建版本）。最终会生成两个文件：`Phobos.dll` 和 `Phobos.pdb`。
2. 将这些文件放入游戏根目录（即您的 `gamemd.exe` 所在的位置）。
3. 要使用 Phobos（以及所有其他已安装且兼容的 Syringe 拓展引擎，包括 Ares）启动游戏，你需要在命令行中执行 `Syringe.exe "gamemd.exe" [gamemd.exe 的命令行参数]`（如果不需要参数，请省略）。Ares 软件包中的 `RunAres.bat` 也有相同的功能，因此也可以使用。

如果您已经在 mod 中使用了 Ares，只需将上述 Phobos 文件放到游戏根目录中，Syringe 就会自动加载 Phobos。这也适用于使用 XNA 客户端和 Syringe 的 mod；如果您的 mod 尚未使用 Syringe 和 Ares（或者您尚未设置客户端），我们建议您使用 [Starkku 的 CnCNet 客户端 mod 基底](https://github.com/Starkku/cncnet-client-mod-base)，它与 Ares 和 Phobos 兼容并且开袋即食。

您可能用到的其他文件与工具位于 [Phobos 补充资源库](https://github.com/Phobos-developers/PhobosSupplementaries)。

在默认情况下 Phobos 不会做任何非常明显的更改，除了一些错误修复。

要了解如何使用 Phobos 功能，请参阅官方文档。

文档
-------------

- [官方文档](https://phobos.readthedocs.io) （也有 [英文](https://phobos.readthedocs.io/en/latest) 版本）
- [社区中文文档](https://docs.qq.com/doc/p/dc3da1ce39a6e787b6e133f7d33d6aebef581cb4)
  - 由于官方文档的中文翻译尚不完善，目前建议中国用户使用社区文档

您可以在右下角切换版本（默认显示最新开发的每夜构建版本），也可以下载 PDF 版本
（PDF 下载功能仅限英文文档）。
文档分为几个大类，每类在侧边栏上都有一个页面。
每个页面的内容又分为多个子类别，包括建筑、科技类型、步兵、超级武器或其他。

### 如何阅读代码片段

```ini
; 一个条目应位于哪个小节
; 可以是自由的命名形式 - 在这种情况下，注释将会解释它是什么
; 如果找不到注释 - 那么这是一个固定且精确的名称
[一个名称]            ; BuildingType
; 标签名=默认值       ; 接受的类型与可选的解释
; 如果等号右侧没有任何内容，则默认值为空/不存在
; 如果这些键已经设置了它们的值，那么它们只能通过
; 设置为 <default>, <none> 或 none 来重设为默认值
; 对于值列表则仅有 <default> 可以清除整个列表
; 如果默认值不是静态的，那么会在注释中写明并加以解释
UIDescription=<none> ; CSF 条目
```

手动生成
-----------------

0. 使用 `.vsconfig` 中列出的依赖项安装 **Visual Studio** （建议安装2022版，最低安装2019版）（打开项目时会提示安装缺失的依赖项，也可以运行 VS 安装程序并导入配置）。
  2.如果您更喜欢使用 **Visual Studio Code**，也可以使用 `.vsconfig` 中的依赖项安装 **VS Build Tools**。
  3.也可以不使用代码编辑器或集成开发环境而是通过项目中包含的 **命令行脚本** 进行构建。
1. 通过您最喜欢的 git 客户端递归克隆该仓库（也会同时克隆 YRpp）。
2. 对于构建扩展：
   - 在 Visual Studio 中：在 VS 中打开解决方案文件并构建（建议使用 `Debug` 构建配置）；
   - 在 VSCode 中：打开项目目录，点击`运行构建任务…`（`Ctrl+Shift+B`）；
   - 其他：运行 `scripts/build_debug.bat`。
3. 构建完成后，生成的 `Phobos.dll` 和 `Phobos.pdb` 将被放置在与执行的构建配置名称相同的子目录中。

鸣谢
-------

### 开发者
- **Belonit (Gluk-v48)** - 项目作者
- **Kerbiter (Metadorius)** - 项目共同作者，BDFL，维护者（[Patreon](https://www.patreon.com/kerbiter)，私信我获取 PayPal 以免额外费用）
- **Starkku** - 共同维护者，开发者（[Patreon](https://www.patreon.com/Starkku)）
- **Uranusian (Thrifinesma)** - 开发者，中国社区大使
- **secsome (SEC-SOME)** - 开发者
- **Otamaa (Fahroni, BoredEXE)** - 开发者（[PayPal](https://paypal.me/GeneralOtama)）
- **FS-21** - 开发者
- **Morton (MortonPL)** - 共同维护者，开发者
- **Trsdy (chaserli)** - 共同维护者，开发者

所有贡献者名单参见 [完整致谢列表](CREDITS.md)。

感谢所有使用 Phobos、测试更改和报告 Bug 的人！

感谢所有使用 Phobos、测试更改和报告 Bug 的人！ 你可以将我们的 Logo（单色版本可在 [此处](https://github.com/Phobos-developers/Phobos/blob/develop/logo-mono.png) 获取）在你的客户端／启动器中展示（使其能够打开 Phobos 项目的 GitHub 主页以显得更加豪华）、将其链接到 Phobos 仓库、通过上方链接想我没贡献代码或进行捐助等方式来表达你的感谢并为本项目提供助力。

法律与许可证
-----

[![GPL v3](https://www.gnu.org/graphics/gplv3-127x51.png)](https://opensource.org/license/GPL-3.0)

Phobos 是一个非官方的开源社区合作项目，旨在扩展《红色警戒2尤里的复仇》引擎以用于 Mod 制作与兼容性目的。

作为一项修改，该项目符合 [EA C&C 修改指南](https://www.ea.com/games/command-and-conquer/command-and-conquer-remastered/modding-faq)；

如果项目许可与修改指南之间存在冲突，则以指南中的规则为准

（例如，该项目不应用于商业用途或用于盈利）。

本项目与艺电公司（Electronic Arts Inc.）没有任何直接关联。「Command & Conquer」、「Command & Conquer Red Alert 2」 和 「Command & Conquer Yuri's Revenge」均为艺电公司的注册商标。版权所有。
