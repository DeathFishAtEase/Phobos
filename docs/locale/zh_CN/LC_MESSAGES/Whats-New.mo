��          �                 	             6     Q     ^  �   o  	               �   )  �   
  �   �     �  
   �  w  �       %   $     J  	   `     j     �        	          �   $  �   �  T   �     �  	   	   Changelog For Map Editor (Final Alert 2) From older Phobos versions From vanilla In `FAData.ini`: Key `rulesmd.ini->[SOMETECHNOTYPE]->Deployed.RememberTarget` is deprecated and can be removed now, the bugfix for `DeployToFire` deployers is now always on. Migrating New: Phobos fixes: Radiation now has owner by default, which means that radiation kills will affect score and radiation field will respect `Affects...` entries. You can override that with `rulesmd.ini->[SOMEWEAPONTYPE]->Rad.NoOwner=yes` entry. SHP debris hardcoded shadows now respect `Shadow=no` tag value, and due to it being the default value they wouldn't have hardcoded shadows anymore by default. Override this by specifying `Shadow=yes` for SHP debris. This page lists the history of changes across stable Phobos releases and also all the stuff that requires modders to change something in their mods to accomodate. Vanilla fixes: What's New Project-Id-Version: Phobos 
Report-Msgid-Bugs-To: 
POT-Creation-Date: 2021-08-16 14:17+0800
PO-Revision-Date: YEAR-MO-DA HO:MI+ZONE
Last-Translator: FULL NAME <EMAIL@ADDRESS>
Language: zh_CN
Language-Team: zh_CN <LL@li.org>
Plural-Forms: nplurals=1; plural=0
MIME-Version: 1.0
Content-Type: text/plain; charset=utf-8
Content-Transfer-Encoding: 8bit
Generated-By: Babel 2.9.1
 更新日志 对地图编辑器（Final Alert 2） 由旧版本火卫一 由原版 在`FAData.ini`中： `rulesmd.ini->[SOMETECHNOTYPE]->Deployed.RememberTarget`已弃用并被移除，对`DeployToFire`的修复现在一直开启。 迁移 新的： 火卫一修复： 辐射现在默认拥有所属方，使得辐射击杀可以被算入得分，且辐射场也会遵循`Affects...`设定。可以通过`rulesmd.ini->[SOMEWEAPONTYPE]->Rad.NoOwner=yes`覆盖此设定。 SHP碎片硬编码的影子现在遵循`Shadow=no`，并且由于这就是默认值，所以他们不再拥有硬编码的影子。为SHP指定`Shadow=yes`以覆盖此设定。 此页面列出了项目的更新日志以及需要modder对mod做的必要改动。 原版修复： 新东西 