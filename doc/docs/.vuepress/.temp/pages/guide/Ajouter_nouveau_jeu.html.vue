<template><div><h1 id="🎀-cree-un-nouveau-jeu" tabindex="-1"><a class="header-anchor" href="#🎀-cree-un-nouveau-jeu" aria-hidden="true">#</a> 🎀 Crée un nouveau jeu</h1>
<h2 id="📰-prerequis" tabindex="-1"><a class="header-anchor" href="#📰-prerequis" aria-hidden="true">#</a> 📰 Prérequis</h2>
<ul>
<li>Avoir lu la page <RouterLink to="/guide/Introduction.html">Introduction</RouterLink></li>
<li>Avoir lu la page <RouterLink to="/guide/How_to_use.html">Comment utiliser l'arcade ?</RouterLink></li>
</ul>
<h2 id="🎮-creation-d-un-nouveau-jeu" tabindex="-1"><a class="header-anchor" href="#🎮-creation-d-un-nouveau-jeu" aria-hidden="true">#</a> 🎮 Création d'un nouveau jeu</h2>
<p>Pour créer un nouveau jeu, vous devez vous rendre dans le répertoire <code v-pre>games/</code> et créer un nouveau répertoire avec le nom de votre jeu.</p>
<div class="language-bash line-numbers-mode" data-ext="sh"><pre v-pre class="language-bash"><code>$ <span class="token builtin class-name">cd</span> games/
$ <span class="token builtin class-name">pwd</span>
<span class="token punctuation">[</span><span class="token punctuation">..</span>.<span class="token punctuation">]</span>/arcade/games
$ <span class="token function">mkdir</span> <span class="token punctuation">[</span>game_name<span class="token punctuation">]</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><p>Ensuite, vous devez créer un dossier include et un dossier src dans votre répertoire.</p>
<div class="language-bash line-numbers-mode" data-ext="sh"><pre v-pre class="language-bash"><code>$ <span class="token builtin class-name">cd</span> <span class="token punctuation">[</span>game_name<span class="token punctuation">]</span>
$ <span class="token function">mkdir</span> include
$ <span class="token function">mkdir</span> src
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><p>Pour ajouter un nouveau jeu, vous allez devoir créer une classe qui hérite de l'interface <code v-pre>IGameModule</code>.</p>
<div class="custom-container warning"><p class="custom-container-title"><ins> Qu'est ce que l'interface IGameModule ? </ins></p>
<p>L'interface <code v-pre>IGameModule</code> est une interface qui contient des méthodes qui doivent être implémentées dans votre classe. Pour plus d'informations, vous pouvez vous rendre dans le répertoire <code v-pre>api/game/IGameModule.hpp</code>.</p>
<p>Cette interface permet d'être utilisé par le programme arcade et de pouvoir changer de jeu sans avoir à recompiler le programme. Et ainsi, en utilisant le jeu que vous voulez.</p>
</div>
<p>A présent, rendez vous dans le include, où vous allez comment à crée votre <code v-pre>class</code> qui hérite de la classe <code v-pre>IGameModule</code>.</p>
<div class="language-cpp line-numbers-mode" data-ext="cpp"><pre v-pre class="language-cpp"><code><span class="token comment">// include/[game_name].hpp</span>

<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span> <span class="token string">"../../../api/game/IGameModule.hpp"</span></span>

<span class="token keyword">namespace</span> arcade <span class="token punctuation">{</span>
    <span class="token keyword">class</span> <span class="token punctuation">[</span>game_name<span class="token punctuation">]</span> <span class="token operator">:</span> <span class="token keyword">public</span> IGameModule <span class="token punctuation">{</span>
        <span class="token keyword">public</span><span class="token operator">:</span>
            <span class="token keyword">void</span> <span class="token function">handleInput</span><span class="token punctuation">(</span>Input input<span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">void</span> <span class="token function">update</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">void</span> <span class="token function">reset</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">bool</span> <span class="token function">isGameOver</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">const</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            std<span class="token double-colon punctuation">::</span>vector<span class="token operator">&lt;</span>std<span class="token double-colon punctuation">::</span>vector<span class="token operator">&lt;</span>IModule<span class="token double-colon punctuation">::</span>Asset<span class="token operator">>></span> <span class="token function">getLayers</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
            <span class="token keyword">int</span> <span class="token function">getScore</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">const</span> <span class="token keyword">override</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span><span class="token punctuation">;</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><p>Ensuite, rendez vous dans le dossier src, et créez votre fichier source.</p>
<div class="language-cpp line-numbers-mode" data-ext="cpp"><pre v-pre class="language-cpp"><code><span class="token comment">// src/[game_name].cpp</span>

<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span> <span class="token string">"../../include/[game_name].hpp"</span></span>

<span class="token keyword">namespace</span> arcade <span class="token punctuation">{</span>
    <span class="token keyword">void</span> <span class="token punctuation">[</span>game_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">handleInput</span><span class="token punctuation">(</span>Input input<span class="token punctuation">)</span> <span class="token punctuation">{</span>

    <span class="token punctuation">}</span>

    <span class="token keyword">void</span> <span class="token punctuation">[</span>game_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">update</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>

    <span class="token punctuation">}</span>

    <span class="token keyword">void</span> <span class="token punctuation">[</span>game_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">reset</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>

    <span class="token punctuation">}</span>

    <span class="token keyword">bool</span> <span class="token punctuation">[</span>game_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">isGameOver</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">const</span> <span class="token punctuation">{</span>
        <span class="token keyword">return</span> <span class="token boolean">false</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>

    std<span class="token double-colon punctuation">::</span>vector<span class="token operator">&lt;</span>std<span class="token double-colon punctuation">::</span>vector<span class="token operator">&lt;</span>IModule<span class="token double-colon punctuation">::</span>Asset<span class="token operator">>></span> <span class="token punctuation">[</span>game_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">getLayers</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
        <span class="token keyword">return</span> std<span class="token double-colon punctuation">::</span><span class="token generic-function"><span class="token function">vector</span><span class="token generic class-name"><span class="token operator">&lt;</span>std<span class="token double-colon punctuation">::</span>vector<span class="token operator">&lt;</span>IModule<span class="token double-colon punctuation">::</span>Asset<span class="token operator">>></span></span></span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>

    <span class="token keyword">int</span> <span class="token punctuation">[</span>game_name<span class="token punctuation">]</span><span class="token double-colon punctuation">::</span><span class="token function">getScore</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">const</span> <span class="token punctuation">{</span>
        <span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>

    <span class="token keyword">extern</span> <span class="token string">"C"</span> IGameModule <span class="token operator">*</span><span class="token function">entryPoint</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
        <span class="token keyword">return</span> <span class="token keyword">new</span> <span class="token punctuation">[</span>game_name<span class="token punctuation">]</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>

    <span class="token keyword">extern</span> <span class="token string">"C"</span> <span class="token keyword">void</span> <span class="token function">deleteEntryPoint</span><span class="token punctuation">(</span>IGameModule <span class="token operator">*</span>game<span class="token punctuation">)</span> <span class="token punctuation">{</span>
        <span class="token keyword">delete</span> game<span class="token punctuation">;</span>
    <span class="token punctuation">}</span>

<span class="token punctuation">}</span><span class="token punctuation">;</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><p>Puis coder, les fonctions nécessaires pour le fonctionnement de votre jeu.</p>
<h2 id="📝-ajout-du-jeu-dans-le-makefile" tabindex="-1"><a class="header-anchor" href="#📝-ajout-du-jeu-dans-le-makefile" aria-hidden="true">#</a> 📝 Ajout du jeu dans le Makefile</h2>
<p>Pour que votre jeu soit compilé, vous devez l'ajouter dans le Makefile.</p>
<div class="language-makefile line-numbers-mode" data-ext="makefile"><pre v-pre class="language-makefile"><code>
MAKEFLAGS <span class="token operator">+=</span> --no-print-directory

SRC_DIRS <span class="token operator">=</span> ./src

LIB <span class="token operator">=</span> [game_name].so

SRCS <span class="token operator">:=</span> <span class="token variable">$</span><span class="token punctuation">(</span><span class="token function">shell</span> find <span class="token variable">$</span><span class="token punctuation">(</span>SRC_DIRS<span class="token punctuation">)</span> -name <span class="token string">"*.cpp"</span><span class="token punctuation">)</span>
OBJS <span class="token operator">=</span> <span class="token variable">$</span><span class="token punctuation">(</span>SRCS<span class="token punctuation">:</span>.cpp<span class="token operator">=</span>.o<span class="token punctuation">)</span>

CPPFLAGS <span class="token operator">=</span> <span class="token variable">$</span><span class="token punctuation">(</span><span class="token function">shell</span> find ../../api ./<span class="token keyword">include</span>  -type d <span class="token operator">|</span> awk <span class="token string">'{printf "-I%s ", $$0}'</span><span class="token punctuation">)</span>

CC <span class="token operator">=</span> g++

<span class="token target symbol">all</span> <span class="token punctuation">:</span> <span class="token variable">$</span><span class="token punctuation">(</span>LIB<span class="token punctuation">)</span>
	<span class="token operator">@</span>mv <span class="token variable">$</span><span class="token punctuation">(</span>LIB<span class="token punctuation">)</span> ../../lib

<span class="token target symbol"><span class="token variable">$</span>(LIB)</span> <span class="token punctuation">:</span> <span class="token variable">$</span><span class="token punctuation">(</span>OBJS<span class="token punctuation">)</span>
	<span class="token operator">@</span><span class="token variable">$</span><span class="token punctuation">(</span>CC<span class="token punctuation">)</span> -shared -fPIC -o <span class="token variable">$</span><span class="token punctuation">(</span>LIB<span class="token punctuation">)</span> <span class="token variable">$</span><span class="token punctuation">(</span>SRCS<span class="token punctuation">)</span> <span class="token variable">$</span><span class="token punctuation">(</span>CFLAGS<span class="token punctuation">)</span> <span class="token variable">$</span><span class="token punctuation">(</span>CPPFLAGS<span class="token punctuation">)</span> -lcurses

<span class="token target symbol">clean</span> <span class="token punctuation">:</span>
	<span class="token operator">@</span><span class="token variable">$</span><span class="token punctuation">(</span>RM<span class="token punctuation">)</span> <span class="token variable">$</span><span class="token punctuation">(</span>OBJS<span class="token punctuation">)</span>
	<span class="token operator">@</span><span class="token variable">$</span><span class="token punctuation">(</span>RM<span class="token punctuation">)</span> *.gcda
	<span class="token operator">@</span><span class="token variable">$</span><span class="token punctuation">(</span>RM<span class="token punctuation">)</span> *.gcno

<span class="token target symbol">fclean</span> <span class="token punctuation">:</span> clean
	<span class="token operator">@</span><span class="token variable">$</span><span class="token punctuation">(</span>RM<span class="token punctuation">)</span> <span class="token variable">$</span><span class="token punctuation">(</span>LIB<span class="token punctuation">)</span>
	<span class="token operator">@</span><span class="token variable">$</span><span class="token punctuation">(</span>RM<span class="token punctuation">)</span> ../../lib/<span class="token variable">$</span><span class="token punctuation">(</span>LIB<span class="token punctuation">)</span>

<span class="token target symbol">re</span> <span class="token punctuation">:</span> fclean all
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><div class="custom-container warning"><p class="custom-container-title"><ins> Qu'est ce que le Makefile ? </ins></p>
<p>Le Makefile est un fichier qui permet de compiler un programme. Il contient des règles qui permettent de compiler un programme.</p>
</div>
<div class="custom-container danger"><p class="custom-container-title"><ins> Attention ! </ins></p>
<p>Vous devez remplacer <code v-pre>[game_name]</code> par le nom de votre jeu. La variable <code v-pre>LIB</code> doit contenir le nom de votre jeu suivi de <code v-pre>.so</code></p>
</div>
<p>Une fois votre <code v-pre>Makefile</code> terminé, vous pouvez compiler votre jeu.</p>
<div class="language-bash line-numbers-mode" data-ext="sh"><pre v-pre class="language-bash"><code>$ <span class="token builtin class-name">pwd</span>
<span class="token punctuation">[</span><span class="token punctuation">..</span>.<span class="token punctuation">]</span>/arcade/games/<span class="token punctuation">[</span>game_name<span class="token punctuation">]</span>
$ <span class="token function">make</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><p>A présent, vous pouvez lancer l'arcade et jouer à votre jeu. Il se retrouve dans le répertoire <code v-pre>lib/</code>.</p>
<div class="custom-container tip"><p class="custom-container-title"><ins> Comment lancer l'arcade ? </ins></p>
<p>Pour lancer l'arcade, vous devez vous rendre dans le répertoire <code v-pre>arcade/</code> et lancer le programme <code v-pre>arcade</code>.</p>
<div class="language-bash line-numbers-mode" data-ext="sh"><pre v-pre class="language-bash"><code>$ <span class="token builtin class-name">cd</span> <span class="token punctuation">..</span>/<span class="token punctuation">..</span>/
$ <span class="token builtin class-name">pwd</span>
<span class="token punctuation">[</span><span class="token punctuation">..</span>.<span class="token punctuation">]</span>/arcade
$ ./arcade <span class="token punctuation">[</span>lib_name<span class="token punctuation">]</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div></div>
</div></template>


