<template><div><h1 id="✨-cree-une-nouvelle-librairie-graphique" tabindex="-1"><a class="header-anchor" href="#✨-cree-une-nouvelle-librairie-graphique" aria-hidden="true">#</a> ✨ Crée une nouvelle librairie graphique</h1>
<h2 id="📝-pre-requis" tabindex="-1"><a class="header-anchor" href="#📝-pre-requis" aria-hidden="true">#</a> 📝 Pré-requis</h2>
<ul>
<li>Avoir lu la page <RouterLink to="/guide/Introduction.html">Introduction</RouterLink></li>
<li>Avoir lu la page <RouterLink to="/guide/How_to_use.html">Comment utiliser l'arcade ?</RouterLink></li>
</ul>
<h2 id="🆕-creation-d-une-nouvelle-librairie-graphique" tabindex="-1"><a class="header-anchor" href="#🆕-creation-d-une-nouvelle-librairie-graphique" aria-hidden="true">#</a> 🆕 Création d'une nouvelle librairie graphique</h2>
<p>Pour créer une nouvelle librairie graphique, vous devez vous rendre dans le répertoire <code v-pre>graphicals/</code> et créer un nouveau répertoire avec le nom de votre librairie.</p>
<div class="language-bash line-numbers-mode" data-ext="sh"><pre v-pre class="language-bash"><code>$ <span class="token builtin class-name">cd</span> graphicals/
$ <span class="token function">mkdir</span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div></div></div><p>Ensuite, vous devez créer un dossier include et un dossier src dans votre répertoire.</p>
<div class="language-bash line-numbers-mode" data-ext="sh"><pre v-pre class="language-bash"><code>$ <span class="token builtin class-name">cd</span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span>
$ <span class="token function">mkdir</span> include
$ <span class="token function">mkdir</span> src
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><p>Pour ajouter une nouvelle librairie graphique, vous allez devoir créer une classe qui hérite de l'interface <code v-pre>IDisplayModule</code>.</p>
<div class="custom-container warning"><p class="custom-container-title"><ins> Qu'est ce que l'interface IDisplayModule ? </ins></p>
<p>L'interface <code v-pre>IDisplayModule</code> est une interface qui contient des méthodes qui doivent être implémentées dans votre classe. Pour plus d'informations, vous pouvez vous rendre dans le répertoire <code v-pre>api/graphicals/IDisplayModule.hpp</code>.</p>
<p>Cette interface permet d'être utilisé par le programme <code v-pre>arcade</code> et de pouvoir changer de librairie graphique sans avoir à recompiler le programme. Et ainsi, en utilisant la librairie graphique que vous voulez.</p>
</div>
<p>A présent, rendez vous dans le include, où vous allez comment à crée votre <code v-pre>class</code> qui hérite de la classe <code v-pre>IDisplayModule</code>.</p>
<div class="language-cpp line-numbers-mode" data-ext="cpp"><pre v-pre class="language-cpp"><code><span class="token comment">// include/[lib_name].hpp</span>

<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span> <span class="token string">"../../../api/graphicals/IDisplayModule.hpp"</span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span> <span class="token string">"../../../api/core/dll/DLLType.hpp"</span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span> <span class="token string">&lt;ncurses.h></span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span> <span class="token string">&lt;iostream></span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span> <span class="token string">&lt;memory></span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span> <span class="token string">&lt;vector></span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span> <span class="token string">&lt;fstream></span></span>

<span class="token keyword">namespace</span> arcade <span class="token punctuation">{</span>
    <span class="token keyword">class</span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span> <span class="token operator">:</span> <span class="token keyword">public</span> IDisplayModule <span class="token punctuation">{</span>
        <span class="token keyword">public</span><span class="token operator">:</span>
            <span class="token keyword">const</span> std<span class="token double-colon punctuation">::</span>string <span class="token operator">&amp;</span><span class="token function">getName</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">const</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">void</span> <span class="token function">createWindow</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">void</span> <span class="token function">destroyWindow</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">void</span> <span class="token function">displayWindow</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">void</span> <span class="token function">clearWindow</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            std<span class="token double-colon punctuation">::</span>queue<span class="token operator">&lt;</span>Input<span class="token operator">></span> <span class="token function">getInputKeys</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">void</span> <span class="token function">drawImage</span><span class="token punctuation">(</span><span class="token keyword">const</span> std<span class="token double-colon punctuation">::</span>string <span class="token operator">&amp;</span>path<span class="token punctuation">,</span> <span class="token keyword">const</span> Vector2f <span class="token operator">&amp;</span>pos<span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">void</span> <span class="token function">drawText</span><span class="token punctuation">(</span><span class="token keyword">const</span> std<span class="token double-colon punctuation">::</span>string <span class="token operator">&amp;</span>text<span class="token punctuation">,</span> <span class="token keyword">const</span> Vector2f <span class="token operator">&amp;</span>pos<span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">void</span> <span class="token function">drawText</span><span class="token punctuation">(</span><span class="token keyword">const</span> std<span class="token double-colon punctuation">::</span>string <span class="token operator">&amp;</span>text<span class="token punctuation">,</span> <span class="token keyword">const</span> Vector2f <span class="token operator">&amp;</span>pos<span class="token punctuation">,</span> <span class="token keyword">const</span> Color <span class="token operator">&amp;</span>color<span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">void</span> <span class="token function">drawText</span><span class="token punctuation">(</span><span class="token keyword">const</span> std<span class="token double-colon punctuation">::</span>string <span class="token operator">&amp;</span>text<span class="token punctuation">,</span> <span class="token keyword">const</span> Vector2f <span class="token operator">&amp;</span>pos<span class="token punctuation">,</span> <span class="token keyword">const</span> TextStyle <span class="token operator">&amp;</span>style<span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">void</span> <span class="token function">drawText</span><span class="token punctuation">(</span><span class="token keyword">const</span> std<span class="token double-colon punctuation">::</span>string <span class="token operator">&amp;</span>text<span class="token punctuation">,</span> <span class="token keyword">const</span> Vector2f <span class="token operator">&amp;</span>pos<span class="token punctuation">,</span> <span class="token keyword">const</span> Color <span class="token operator">&amp;</span>color<span class="token punctuation">,</span> <span class="token keyword">const</span> TextStyle <span class="token operator">&amp;</span>style<span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">void</span> <span class="token function">drawAsset</span><span class="token punctuation">(</span><span class="token keyword">const</span> Asset <span class="token operator">&amp;</span>asset<span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">void</span> <span class="token function">drawPixel</span><span class="token punctuation">(</span><span class="token keyword">const</span> Vector2i <span class="token operator">&amp;</span>pos<span class="token punctuation">,</span> <span class="token keyword">const</span> Vector2i size<span class="token punctuation">,</span> <span class="token keyword">const</span> Color <span class="token operator">&amp;</span>color<span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
        <span class="token keyword">protected</span><span class="token operator">:</span>
        <span class="token keyword">private</span><span class="token operator">:</span>
            std<span class="token double-colon punctuation">::</span>string _name <span class="token operator">=</span> <span class="token string">"[lib_name]"</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><p>Une fois votre classe créée, vous devez maintenant implémenter les méthodes de l'interface <code v-pre>IDisplayModule</code>.</p>
<div class="language-cpp line-numbers-mode" data-ext="cpp"><pre v-pre class="language-cpp"><code>
<span class="token comment">// src/[lib_name].cpp</span>

<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span> <span class="token string">"../../include/[lib_name].hpp"</span></span>

<span class="token keyword">namespace</span> arcade <span class="token punctuation">{</span>
    <span class="token keyword">const</span> std<span class="token double-colon punctuation">::</span>string <span class="token operator">&amp;</span><span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">getName</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">const</span>
    <span class="token punctuation">{</span>
        <span class="token keyword">return</span> _name<span class="token punctuation">;</span>
    <span class="token punctuation">}</span>

    <span class="token keyword">void</span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">createWindow</span><span class="token punctuation">(</span><span class="token punctuation">)</span>
    <span class="token punctuation">{</span>

    <span class="token punctuation">}</span>

    <span class="token keyword">void</span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">destroyWindow</span><span class="token punctuation">(</span><span class="token punctuation">)</span>
    <span class="token punctuation">{</span>

    <span class="token punctuation">}</span>

    <span class="token keyword">void</span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">displayWindow</span><span class="token punctuation">(</span><span class="token punctuation">)</span>
    <span class="token punctuation">{</span>

    <span class="token punctuation">}</span>

    <span class="token keyword">void</span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">clearWindow</span><span class="token punctuation">(</span><span class="token punctuation">)</span>
    <span class="token punctuation">{</span>

    <span class="token punctuation">}</span>

    std<span class="token double-colon punctuation">::</span>queue<span class="token operator">&lt;</span>Input<span class="token operator">></span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">getInputKeys</span><span class="token punctuation">(</span><span class="token punctuation">)</span>
    <span class="token punctuation">{</span>
        std<span class="token double-colon punctuation">::</span>queue<span class="token operator">&lt;</span>Input<span class="token operator">></span> input<span class="token punctuation">;</span>

        <span class="token keyword">return</span> input<span class="token punctuation">;</span>
    <span class="token punctuation">}</span>

    <span class="token keyword">void</span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">drawImage</span><span class="token punctuation">(</span><span class="token keyword">const</span> std<span class="token double-colon punctuation">::</span>string <span class="token operator">&amp;</span>path<span class="token punctuation">,</span> <span class="token keyword">const</span> Vector2f <span class="token operator">&amp;</span>pos<span class="token punctuation">)</span>
    <span class="token punctuation">{</span>

    <span class="token punctuation">}</span>

    <span class="token keyword">void</span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">drawText</span><span class="token punctuation">(</span><span class="token keyword">const</span> std<span class="token double-colon punctuation">::</span>string <span class="token operator">&amp;</span>text<span class="token punctuation">,</span> <span class="token keyword">const</span> Vector2f <span class="token operator">&amp;</span>pos<span class="token punctuation">)</span>
    <span class="token punctuation">{</span>

    <span class="token punctuation">}</span>

    <span class="token keyword">void</span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">drawText</span><span class="token punctuation">(</span><span class="token keyword">const</span> std<span class="token double-colon punctuation">::</span>string <span class="token operator">&amp;</span>text<span class="token punctuation">,</span> <span class="token keyword">const</span> Vector2f <span class="token operator">&amp;</span>pos<span class="token punctuation">,</span> <span class="token keyword">const</span> Color <span class="token operator">&amp;</span>color<span class="token punctuation">)</span>
    <span class="token punctuation">{</span>

    <span class="token punctuation">}</span>

    <span class="token keyword">void</span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">drawText</span><span class="token punctuation">(</span><span class="token keyword">const</span> std<span class="token double-colon punctuation">::</span>string <span class="token operator">&amp;</span>text<span class="token punctuation">,</span> <span class="token keyword">const</span> Vector2f <span class="token operator">&amp;</span>pos<span class="token punctuation">,</span> <span class="token keyword">const</span> TextStyle <span class="token operator">&amp;</span>style<span class="token punctuation">)</span>
    <span class="token punctuation">{</span>

    <span class="token punctuation">}</span>

    <span class="token keyword">void</span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">drawText</span><span class="token punctuation">(</span><span class="token keyword">const</span> std<span class="token double-colon punctuation">::</span>string <span class="token operator">&amp;</span>text<span class="token punctuation">,</span> <span class="token keyword">const</span> Vector2f <span class="token operator">&amp;</span>pos<span class="token punctuation">,</span> <span class="token keyword">const</span> Color <span class="token operator">&amp;</span>color<span class="token punctuation">,</span> <span class="token keyword">const</span> TextStyle <span class="token operator">&amp;</span>style<span class="token punctuation">)</span>
    <span class="token punctuation">{</span>

    <span class="token punctuation">}</span>

    <span class="token keyword">void</span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">drawAsset</span><span class="token punctuation">(</span><span class="token keyword">const</span> Asset <span class="token operator">&amp;</span>asset<span class="token punctuation">)</span>
    <span class="token punctuation">{</span>

    <span class="token punctuation">}</span>

    <span class="token keyword">void</span> <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">drawPixel</span><span class="token punctuation">(</span><span class="token keyword">const</span> Vector2i <span class="token operator">&amp;</span>pos<span class="token punctuation">,</span> <span class="token keyword">const</span> Vector2i size<span class="token punctuation">,</span> <span class="token keyword">const</span> Color <span class="token operator">&amp;</span>color<span class="token punctuation">)</span>
    <span class="token punctuation">{</span>

    <span class="token punctuation">}</span>

<span class="token punctuation">}</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><p>Une fois que vous avez implémenté les méthodes de l'interface <code v-pre>IDisplayModule</code>, vous pouvez maintenant compiler votre librairie. Pour se faire vous allez devoir crée un <code v-pre>Makefile</code> dans votre répertoire.</p>
<div class="custom-container warning"><p class="custom-container-title"><ins> Qu'est ce que le Makefile ? </ins></p>
<p>Le Makefile est un fichier qui permet de compiler un programme. Il contient des règles qui permettent de compiler un programme.</p>
</div>
<div class="custom-container danger"><p class="custom-container-title"><ins> Attention ! </ins></p>
<p>Vous devez remplacer <code v-pre>[game_name]</code> par le nom de votre jeu. La variable <code v-pre>LIB</code> doit contenir le nom de votre jeu suivi de <code v-pre>.so</code></p>
</div>
<div class="language-Makefile line-numbers-mode" data-ext="Makefile"><pre v-pre class="language-Makefile"><code>MAKEFLAGS += --no-print-directory

SRC_DIRS = ./src

LIB = libarcade_[lib_name].so

SRCS := $(shell find $(SRC_DIRS) -name &quot;*.cpp&quot;)
OBJS = $(SRCS:.cpp=.o)

CFLAGS =
CPPFLAGS = $(shell find ../../api ./include  -type d | awk '{printf &quot;-I%s &quot;, $$0}')

CC = g++

all : $(LIB)
	@mv $(LIB) ../../lib

$(LIB) : $(OBJS)
	@$(CC) -shared -fPIC -o $(LIB) $(SRCS) $(CFLAGS) $(CPPFLAGS) -lcurses

clean :
	@$(RM) $(OBJS)
	@$(RM) *.gcda
	@$(RM) *.gcno

fclean : clean
	@$(RM) $(LIB)
	@$(RM) ../../lib/$(LIB)

re : fclean all
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><p>Une fois que vous avez crée votre <code v-pre>Makefile</code>, vous pouvez maintenant compiler votre librairie.</p>
<div class="language-bash line-numbers-mode" data-ext="sh"><pre v-pre class="language-bash"><code>$ <span class="token builtin class-name">pwd</span>
<span class="token punctuation">[</span><span class="token punctuation">..</span>.<span class="token punctuation">]</span>/arcade/graphicals/<span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span>
$ <span class="token function">make</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><p>Et voilà, votre librairie est maintenant prête à être utilisée par l'arcade. Elle est disponible dans le répertoire <code v-pre>lib/</code> et vous pouvez maintenant l'utiliser dans l'arcade.</p>
</div></template>


