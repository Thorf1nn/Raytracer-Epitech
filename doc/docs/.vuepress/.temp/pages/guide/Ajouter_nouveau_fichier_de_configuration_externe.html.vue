<template><div><h1 id="✨-le-contenu-des-fichiers" tabindex="-1"><a class="header-anchor" href="#✨-le-contenu-des-fichiers" aria-hidden="true">#</a> ✨ Le contenu des fichiers</h1>
<h2 id="📝-pre-requis" tabindex="-1"><a class="header-anchor" href="#📝-pre-requis" aria-hidden="true">#</a> 📝 Pré-requis</h2>
<ul>
<li>Avoir lu la page <RouterLink to="/guide/Introduction.html">Introduction</RouterLink></li>
<li>Avoir lu la page <RouterLink to="/guide/How_to_use.html">Comment utiliser l'arcade ?</RouterLink></li>
</ul>
<h2 id="🆕-le-contenu-des-interfaces" tabindex="-1"><a class="header-anchor" href="#🆕-le-contenu-des-interfaces" aria-hidden="true">#</a> 🆕 Le contenu des Interfaces</h2>
<p>L'ensemble des fonctions disponibles dans le <code v-pre>IPtimitive.hpp</code> regroupe toutes les fonctions essentielles au bon fonctionnement du rendement 3D de chaque forme et des interactions tel que la reflection, la refraction de la lumière.</p>
<div class="custom-container warning"><p class="custom-container-title"><ins> Qu'est ce que l'interface IDisplayModule ? </ins></p>
<p>L'interface <code v-pre>IDisplayModule</code> est une interface qui contient des méthodes qui doivent être implémentées dans votre classe.</p>
<p>Cette interface permet d'apporter un côté générique au code et de proposer un rendu bien plus compréhensible.</p>
</div>
<p>A présent, rendez vous <code v-pre>sources/abstract</code>, où vous allez remarquer <em>l'interface</em> <code v-pre>IPrimitive</code> ainsi que la <em>structure</em> <code v-pre>hitRecord</code>.</p>
<div class="language-cpp line-numbers-mode" data-ext="cpp"><pre v-pre class="language-cpp"><code><span class="token keyword">namespace</span> RayTracer <span class="token punctuation">{</span>
    <span class="token keyword">struct</span> <span class="token class-name">hitRecord</span> <span class="token punctuation">{</span>
        Math<span class="token double-colon punctuation">::</span>Point<span class="token operator">&lt;</span><span class="token number">3</span><span class="token operator">></span> p<span class="token punctuation">;</span>
        Math<span class="token double-colon punctuation">::</span>Vector<span class="token operator">&lt;</span><span class="token number">3</span><span class="token operator">></span> normal<span class="token punctuation">;</span>
        <span class="token keyword">double</span> t<span class="token punctuation">;</span>
        <span class="token keyword">double</span> u<span class="token punctuation">;</span>
        <span class="token keyword">double</span> v<span class="token punctuation">;</span>
        <span class="token keyword">bool</span> frontFace<span class="token punctuation">;</span>
        std<span class="token double-colon punctuation">::</span>shared_ptr<span class="token operator">&lt;</span>RayTracer<span class="token double-colon punctuation">::</span>IMaterial<span class="token operator">></span> matPtr<span class="token punctuation">;</span>

        <span class="token keyword">inline</span> <span class="token keyword">void</span> <span class="token function">setFaceNormal</span><span class="token punctuation">(</span><span class="token keyword">const</span> Math<span class="token double-colon punctuation">::</span>Ray<span class="token operator">&amp;</span> r<span class="token punctuation">,</span> <span class="token keyword">const</span> Math<span class="token double-colon punctuation">::</span>Vector<span class="token operator">&lt;</span><span class="token number">3</span><span class="token operator">></span><span class="token operator">&amp;</span> outwardNormal<span class="token punctuation">)</span> <span class="token punctuation">{</span>
            frontFace <span class="token operator">=</span> r<span class="token punctuation">.</span>direction<span class="token punctuation">.</span><span class="token function">dot</span><span class="token punctuation">(</span>outwardNormal<span class="token punctuation">)</span> <span class="token operator">&lt;</span> <span class="token number">0</span><span class="token punctuation">;</span>
            normal <span class="token operator">=</span> frontFace <span class="token operator">?</span> outwardNormal <span class="token operator">:</span> <span class="token operator">-</span>outwardNormal<span class="token punctuation">;</span>
        <span class="token punctuation">}</span>
    <span class="token punctuation">}</span><span class="token punctuation">;</span>

    <span class="token keyword">class</span> <span class="token class-name">IPrimitive</span> <span class="token punctuation">{</span>
    <span class="token keyword">public</span><span class="token operator">:</span>
        <span class="token keyword">virtual</span> <span class="token operator">~</span><span class="token function">IPrimitive</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token operator">=</span> <span class="token keyword">default</span><span class="token punctuation">;</span>
        <span class="token keyword">virtual</span> <span class="token keyword">bool</span> <span class="token function">hits</span><span class="token punctuation">(</span><span class="token keyword">const</span> Math<span class="token double-colon punctuation">::</span>Ray<span class="token operator">&amp;</span> r<span class="token punctuation">,</span> <span class="token keyword">double</span> Tmin<span class="token punctuation">,</span> <span class="token keyword">double</span> Tmax<span class="token punctuation">,</span> RayTracer<span class="token double-colon punctuation">::</span>hitRecord<span class="token operator">&amp;</span> rec<span class="token punctuation">)</span> <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
        <span class="token keyword">virtual</span> <span class="token keyword">bool</span> <span class="token function">boundingBox</span><span class="token punctuation">(</span><span class="token keyword">double</span> time0<span class="token punctuation">,</span> <span class="token keyword">double</span> time1<span class="token punctuation">,</span> AABB<span class="token operator">&amp;</span> outputBox<span class="token punctuation">)</span> <span class="token keyword">const</span> <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
        <span class="token keyword">virtual</span> <span class="token keyword">void</span> <span class="token function">translate</span><span class="token punctuation">(</span>Math<span class="token double-colon punctuation">::</span>Vector<span class="token operator">&lt;</span><span class="token number">3</span><span class="token operator">></span> direction<span class="token punctuation">)</span> <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
        <span class="token keyword">virtual</span> <span class="token keyword">void</span> <span class="token function">rotation</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
        <span class="token keyword">virtual</span> <span class="token keyword">void</span> <span class="token function">getUv</span><span class="token punctuation">(</span><span class="token keyword">const</span> Math<span class="token double-colon punctuation">::</span>Point<span class="token operator">&lt;</span><span class="token number">3</span><span class="token operator">></span><span class="token operator">&amp;</span> p<span class="token punctuation">,</span> <span class="token keyword">double</span><span class="token operator">&amp;</span> u<span class="token punctuation">,</span> <span class="token keyword">double</span><span class="token operator">&amp;</span> v<span class="token punctuation">)</span> <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><p>Cette interface regroupe l'ensemble des fonctions utilisées au sein des fichiers présents dans le dossier <em>primitive</em>. Toutes ces fonctions possèdent donc le même prototypage.</p>
<div class="custom-container warning"><p class="custom-container-title"><ins> Qu'est ce que cela signifie ? </ins></p>
<p>Tout les fichiers possédant des classes dans le dossier <em>primitves</em> héritent de l'interface <code v-pre>IPrimitive</code>.</p>
<blockquote>
<p>class Box : public RayTracer::IPrimitive {</p>
</blockquote>
<blockquote>
<p>class Cone : public RayTracer::IPrimitive {</p>
</blockquote>
<blockquote>
<p>class Cylinder : public RayTracer::IPrimitive {</p>
</blockquote>
<blockquote>
<p>class Sphere : public RayTracer::IPrimitive {</p>
</blockquote>
<p>Cette interface permet d'apporter un côté générique au code et de proposer un rendu bien plus compréhensible.</p>
</div>
<p>Une fois que vous avez implémenté les méthodes de l'interface <code v-pre>IDisplayModule</code>, vous pouvez maintenant compiler votre librairie. Pour ce faire vous allez devoir créer un <code v-pre>Makefile</code> dans votre répertoire courant.</p>
<h2 id="🔧-les-fonctions-principales" tabindex="-1"><a class="header-anchor" href="#🔧-les-fonctions-principales" aria-hidden="true">#</a> 🔧 Les fonctions principales</h2>
<p>Toutes les formes possèdes une fonction <code v-pre>hits</code> cette fonction est utilisée pour déterminer si un rayon intersecte une forme dans un système de ray tracing. Voici les grandes étapes de son fonctionnement :</p>
<p>Cette fonction est utilisée pour déterminer si un rayon intersecte une sphère dans un système de ray tracing. Voici les grandes étapes de son fonctionnement.</p>
<h1 id="hits" tabindex="-1"><a class="header-anchor" href="#hits" aria-hidden="true">#</a> hits</h1>
<p>Voci le <code v-pre>hits</code> de la Sphère:</p>
<div class="language-cpp line-numbers-mode" data-ext="cpp"><pre v-pre class="language-cpp"><code>    <span class="token keyword">bool</span> <span class="token class-name">Sphere</span><span class="token double-colon punctuation">::</span><span class="token function">hits</span><span class="token punctuation">(</span><span class="token keyword">const</span> Math<span class="token double-colon punctuation">::</span>Ray <span class="token operator">&amp;</span>r<span class="token punctuation">,</span> <span class="token keyword">double</span> Tmin<span class="token punctuation">,</span> <span class="token keyword">double</span> Tmax<span class="token punctuation">,</span> RayTracer<span class="token double-colon punctuation">::</span>hitRecord <span class="token operator">&amp;</span>rec<span class="token punctuation">)</span> <span class="token punctuation">{</span>
        Math<span class="token double-colon punctuation">::</span>Vector<span class="token operator">&lt;</span><span class="token number">3</span><span class="token operator">></span> oc <span class="token operator">=</span> r<span class="token punctuation">.</span>origin <span class="token operator">-</span> center<span class="token punctuation">;</span>
        <span class="token keyword">auto</span> a <span class="token operator">=</span> r<span class="token punctuation">.</span>direction<span class="token punctuation">.</span><span class="token function">lengthSquared</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
        <span class="token keyword">auto</span> b <span class="token operator">=</span> oc<span class="token punctuation">.</span><span class="token function">dot</span><span class="token punctuation">(</span>r<span class="token punctuation">.</span>direction<span class="token punctuation">)</span><span class="token punctuation">;</span>
        <span class="token keyword">auto</span> c <span class="token operator">=</span> oc<span class="token punctuation">.</span><span class="token function">lengthSquared</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token operator">-</span> radius <span class="token operator">*</span> radius<span class="token punctuation">;</span>

        <span class="token keyword">auto</span> discriminant <span class="token operator">=</span> b <span class="token operator">*</span> b <span class="token operator">-</span> a <span class="token operator">*</span> c<span class="token punctuation">;</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span>discriminant <span class="token operator">&lt;</span> <span class="token number">0</span><span class="token punctuation">)</span> <span class="token keyword">return</span> <span class="token boolean">false</span><span class="token punctuation">;</span>
        <span class="token keyword">auto</span> sqrtd <span class="token operator">=</span> std<span class="token double-colon punctuation">::</span><span class="token function">sqrt</span><span class="token punctuation">(</span>discriminant<span class="token punctuation">)</span><span class="token punctuation">;</span>

        <span class="token keyword">auto</span> root <span class="token operator">=</span> <span class="token punctuation">(</span><span class="token operator">-</span>b <span class="token operator">-</span> sqrtd<span class="token punctuation">)</span> <span class="token operator">/</span> a<span class="token punctuation">;</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span>root <span class="token operator">&lt;</span> Tmin <span class="token operator">||</span> Tmax <span class="token operator">&lt;</span> root<span class="token punctuation">)</span> <span class="token punctuation">{</span>
            root <span class="token operator">=</span> <span class="token punctuation">(</span><span class="token operator">-</span>b <span class="token operator">+</span> sqrtd<span class="token punctuation">)</span> <span class="token operator">/</span> a<span class="token punctuation">;</span>
            <span class="token keyword">if</span> <span class="token punctuation">(</span>root <span class="token operator">&lt;</span> Tmin <span class="token operator">||</span> Tmax <span class="token operator">&lt;</span> root<span class="token punctuation">)</span>
                <span class="token keyword">return</span> <span class="token boolean">false</span><span class="token punctuation">;</span>
        <span class="token punctuation">}</span>

        rec<span class="token punctuation">.</span>t <span class="token operator">=</span> root<span class="token punctuation">;</span>
        rec<span class="token punctuation">.</span>p <span class="token operator">=</span> r<span class="token punctuation">.</span><span class="token function">at</span><span class="token punctuation">(</span>rec<span class="token punctuation">.</span>t<span class="token punctuation">)</span><span class="token punctuation">;</span>
        Math<span class="token double-colon punctuation">::</span>Vector<span class="token operator">&lt;</span><span class="token number">3</span><span class="token operator">></span> outwardNormal <span class="token operator">=</span> <span class="token punctuation">(</span>rec<span class="token punctuation">.</span>p <span class="token operator">-</span> center<span class="token punctuation">)</span> <span class="token operator">/</span> radius<span class="token punctuation">;</span>
        rec<span class="token punctuation">.</span><span class="token function">setFaceNormal</span><span class="token punctuation">(</span>r<span class="token punctuation">,</span> outwardNormal<span class="token punctuation">)</span><span class="token punctuation">;</span>
        <span class="token function">getSphereUv</span><span class="token punctuation">(</span>outwardNormal<span class="token punctuation">,</span> rec<span class="token punctuation">.</span>u<span class="token punctuation">,</span> rec<span class="token punctuation">.</span>v<span class="token punctuation">)</span><span class="token punctuation">;</span>
        rec<span class="token punctuation">.</span>matPtr <span class="token operator">=</span> matPtr<span class="token punctuation">;</span>

        <span class="token keyword">return</span> <span class="token boolean">true</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>

    <span class="token keyword">bool</span> <span class="token class-name">Sphere</span><span class="token double-colon punctuation">::</span><span class="token function">boundingBox</span><span class="token punctuation">(</span><span class="token keyword">double</span> time0<span class="token punctuation">,</span> <span class="token keyword">double</span> time1<span class="token punctuation">,</span> AABB<span class="token operator">&amp;</span> outputBox<span class="token punctuation">)</span> <span class="token keyword">const</span> <span class="token punctuation">{</span>
        outputBox <span class="token operator">=</span> AABB<span class="token punctuation">{</span>
            center <span class="token operator">-</span> Math<span class="token double-colon punctuation">::</span>Vector<span class="token operator">&lt;</span><span class="token number">3</span><span class="token operator">></span> <span class="token punctuation">{</span>radius<span class="token punctuation">,</span> radius<span class="token punctuation">,</span> radius<span class="token punctuation">}</span><span class="token punctuation">,</span>
            center <span class="token operator">+</span> Math<span class="token double-colon punctuation">::</span>Vector<span class="token operator">&lt;</span><span class="token number">3</span><span class="token operator">></span> <span class="token punctuation">{</span>radius<span class="token punctuation">,</span> radius<span class="token punctuation">,</span> radius<span class="token punctuation">}</span><span class="token punctuation">}</span><span class="token punctuation">;</span>
    <span class="token keyword">return</span> <span class="token boolean">true</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><div class="custom-container warning"><p class="custom-container-title"><ins> Voici les grandes étapes de son fonctionnement </ins></p>
<blockquote>
<p>1- Calcul des paramètres initiaux</p>
</blockquote>
<blockquote>
<p>2- Calcul du discriminant</p>
</blockquote>
<blockquote>
<p>3- Calcul des racines</p>
</blockquote>
<blockquote>
<p>4- Vérification des limites</p>
</blockquote>
<blockquote>
<p>5- Attribution des valeurs à la structure de données</p>
</blockquote>
<blockquote>
<p>6- Renvoi du résultat</p>
</blockquote>
</div>
<p>En résumé, cette fonction effectue les calculs nécessaires pour déterminer si un <strong>rayon intersecte</strong> une forme et fournit les informations nécessaires sur le point d'intersection, la normale et les coordonnées UV de la forme en question.</p>
<h1 id="getuv" tabindex="-1"><a class="header-anchor" href="#getuv" aria-hidden="true">#</a> getUv</h1>
<p>Cette fonction, appelée &quot;getUv&quot;, est utilisée pour calculer les coordonnées de texture UV d'un point sur une sphère.</p>
<p>Voci le <code v-pre>getUv</code> de la Sphère:</p>
<div class="language-cpp line-numbers-mode" data-ext="cpp"><pre v-pre class="language-cpp"><code>    <span class="token keyword">void</span> <span class="token class-name">Sphere</span><span class="token double-colon punctuation">::</span><span class="token function">getUv</span><span class="token punctuation">(</span><span class="token keyword">const</span> Math<span class="token double-colon punctuation">::</span>Point<span class="token operator">&lt;</span><span class="token number">3</span><span class="token operator">></span><span class="token operator">&amp;</span> p<span class="token punctuation">,</span> <span class="token keyword">double</span><span class="token operator">&amp;</span> u<span class="token punctuation">,</span> <span class="token keyword">double</span><span class="token operator">&amp;</span> v<span class="token punctuation">)</span> <span class="token punctuation">{</span>

        <span class="token keyword">auto</span> theta <span class="token operator">=</span> <span class="token function">acos</span><span class="token punctuation">(</span><span class="token operator">-</span>p<span class="token punctuation">.</span>_points<span class="token punctuation">[</span><span class="token number">1</span><span class="token punctuation">]</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
        <span class="token keyword">auto</span> phi <span class="token operator">=</span> <span class="token function">atan2</span><span class="token punctuation">(</span><span class="token operator">-</span>p<span class="token punctuation">.</span>_points<span class="token punctuation">[</span><span class="token number">2</span><span class="token punctuation">]</span><span class="token punctuation">,</span> p<span class="token punctuation">.</span>_points<span class="token punctuation">[</span><span class="token number">0</span><span class="token punctuation">]</span><span class="token punctuation">)</span> <span class="token operator">+</span> Math<span class="token double-colon punctuation">::</span>pi<span class="token punctuation">;</span>

        u <span class="token operator">=</span> phi <span class="token operator">/</span> <span class="token punctuation">(</span><span class="token number">2</span> <span class="token operator">*</span> Math<span class="token double-colon punctuation">::</span>pi<span class="token punctuation">)</span><span class="token punctuation">;</span>
        v <span class="token operator">=</span> theta <span class="token operator">/</span> Math<span class="token double-colon punctuation">::</span>pi<span class="token punctuation">;</span>
    <span class="token punctuation">}</span>

</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><div class="custom-container warning"><p class="custom-container-title"><ins> Voici les grandes étapes de son fonctionnement </ins></p>
<blockquote>
<p>1- Calcul de l'angle theta</p>
</blockquote>
<blockquote>
<p>2- Calcul de l'angle phi</p>
</blockquote>
<blockquote>
<p>3- Calcul des coordonnées de texture UV</p>
</blockquote>
</div>
<p>En résumé, cette fonction prend un point sur une sphère et calcule les coordonnées de texture UV correspondantes. Ces coordonnées peuvent ensuite être utilisées pour appliquer une texture ou une couleur spécifique à ce point lors du rendu de la forme en question.</p>
<h1 id="boudingbox" tabindex="-1"><a class="header-anchor" href="#boudingbox" aria-hidden="true">#</a> boudingBox</h1>
<p>Cette fonction, appelée &quot;boundingBox&quot;, est utilisée pour calculer la boîte englobante (bounding box) de la sphère sur une période de</p>
<p>Voci le <code v-pre>boudingBox</code> de la Sphère:</p>
<div class="language-cpp line-numbers-mode" data-ext="cpp"><pre v-pre class="language-cpp"><code>    <span class="token keyword">bool</span> <span class="token class-name">Sphere</span><span class="token double-colon punctuation">::</span><span class="token function">boundingBox</span><span class="token punctuation">(</span><span class="token keyword">double</span> time0<span class="token punctuation">,</span> <span class="token keyword">double</span> time1<span class="token punctuation">,</span> AABB<span class="token operator">&amp;</span> outputBox<span class="token punctuation">)</span> <span class="token keyword">const</span> <span class="token punctuation">{</span>
        outputBox <span class="token operator">=</span> AABB<span class="token punctuation">{</span>
            center <span class="token operator">-</span> Math<span class="token double-colon punctuation">::</span>Vector<span class="token operator">&lt;</span><span class="token number">3</span><span class="token operator">></span> <span class="token punctuation">{</span>radius<span class="token punctuation">,</span> radius<span class="token punctuation">,</span> radius<span class="token punctuation">}</span><span class="token punctuation">,</span>
            center <span class="token operator">+</span> Math<span class="token double-colon punctuation">::</span>Vector<span class="token operator">&lt;</span><span class="token number">3</span><span class="token operator">></span> <span class="token punctuation">{</span>radius<span class="token punctuation">,</span> radius<span class="token punctuation">,</span> radius<span class="token punctuation">}</span><span class="token punctuation">}</span><span class="token punctuation">;</span>
    <span class="token keyword">return</span> <span class="token boolean">true</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><div class="custom-container warning"><p class="custom-container-title"><ins> Voici les grandes étapes de son fonctionnement </ins></p>
<blockquote>
<p>1- Calcul des coins de la boîte englobante</p>
</blockquote>
<blockquote>
<p>2- Attribution des valeurs à l'objet de sortie</p>
</blockquote>
<blockquote>
<p>3- Renvoi du résultat</p>
</blockquote>
</div>
<p>En résumé, cette fonction calcule la boîte englobante d'une sphère en utilisant son centre et son rayon, puis attribue les valeurs calculées à la boîte englobante de sortie. La boîte englobante est utilisée pour optimiser les calculs dans le cadre d'un algorithme de rendu ou de détection de collisions.</p>
<h2 id="⚙️-le-fichier-de-configration" tabindex="-1"><a class="header-anchor" href="#⚙️-le-fichier-de-configration" aria-hidden="true">#</a> ⚙️ Le Fichier de configration</h2>
<p>Le fichier Configuration.cpp est le core de la configuration. Il permet de savoir la primitive qui va avec son matériau et sa texture. Le tout est pensé pour qu'il soit facilement extensible.
En effet, le design pattern de la factory est utilisée pour les primitives, les matériaux, les textures et les boxes.
C'est un design pattern qui définit une interface pour créer des objets dans une classe mère, mais délègue le choix des types d’objets à créer aux sous-classes.</p>
<p>Voici un exemple de factory pour les primitives:</p>
<div class="language-cpp line-numbers-mode" data-ext="cpp"><pre v-pre class="language-cpp"><code>_factory <span class="token operator">=</span> <span class="token punctuation">{</span>
    <span class="token punctuation">{</span><span class="token string">"spheres"</span><span class="token punctuation">,</span> <span class="token punctuation">[</span><span class="token keyword">this</span><span class="token punctuation">]</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token operator">-></span> std<span class="token double-colon punctuation">::</span>vector<span class="token operator">&lt;</span>std<span class="token double-colon punctuation">::</span>shared_ptr<span class="token operator">&lt;</span>IPrimitive<span class="token operator">>></span> <span class="token punctuation">{</span> <span class="token keyword">return</span> <span class="token function">createSpheres</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token punctuation">}</span><span class="token punctuation">}</span><span class="token punctuation">,</span>
    <span class="token punctuation">{</span><span class="token string">"planes"</span><span class="token punctuation">,</span> <span class="token punctuation">[</span><span class="token keyword">this</span><span class="token punctuation">]</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token operator">-></span> std<span class="token double-colon punctuation">::</span>vector<span class="token operator">&lt;</span>std<span class="token double-colon punctuation">::</span>shared_ptr<span class="token operator">&lt;</span>IPrimitive<span class="token operator">>></span> <span class="token punctuation">{</span> <span class="token keyword">return</span> <span class="token function">createPlanes</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token punctuation">}</span><span class="token punctuation">}</span><span class="token punctuation">,</span>
    <span class="token punctuation">{</span><span class="token string">"cylinders"</span><span class="token punctuation">,</span> <span class="token punctuation">[</span><span class="token keyword">this</span><span class="token punctuation">]</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token operator">-></span> std<span class="token double-colon punctuation">::</span>vector<span class="token operator">&lt;</span>std<span class="token double-colon punctuation">::</span>shared_ptr<span class="token operator">&lt;</span>IPrimitive<span class="token operator">>></span> <span class="token punctuation">{</span> <span class="token keyword">return</span> <span class="token function">createCylinders</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token punctuation">}</span><span class="token punctuation">}</span><span class="token punctuation">,</span>
    <span class="token punctuation">{</span><span class="token string">"cones"</span><span class="token punctuation">,</span> <span class="token punctuation">[</span><span class="token keyword">this</span><span class="token punctuation">]</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token operator">-></span> std<span class="token double-colon punctuation">::</span>vector<span class="token operator">&lt;</span>std<span class="token double-colon punctuation">::</span>shared_ptr<span class="token operator">&lt;</span>IPrimitive<span class="token operator">>></span> <span class="token punctuation">{</span> <span class="token keyword">return</span> <span class="token function">createCones</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token punctuation">}</span><span class="token punctuation">}</span><span class="token punctuation">,</span>
    <span class="token punctuation">{</span><span class="token string">"boxes"</span><span class="token punctuation">,</span> <span class="token punctuation">[</span><span class="token keyword">this</span><span class="token punctuation">]</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token operator">-></span> std<span class="token double-colon punctuation">::</span>vector<span class="token operator">&lt;</span>std<span class="token double-colon punctuation">::</span>shared_ptr<span class="token operator">&lt;</span>IPrimitive<span class="token operator">>></span> <span class="token punctuation">{</span> <span class="token keyword">return</span> <span class="token function">createBoxes</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token punctuation">}</span><span class="token punctuation">}</span>
<span class="token punctuation">}</span><span class="token punctuation">;</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><p>On utilise pour cela une <code v-pre>std::unordered_map</code> qui contient une <code v-pre>std::string</code> pour la clé et une <code v-pre>std::function</code> pour la valeur.</p>
<p>Pour l'utiliser c'est très simple, il suffit de l'appeler comme ceci:</p>
<div class="language-cpp line-numbers-mode" data-ext="cpp"><pre v-pre class="language-cpp"><code><span class="token keyword">if</span> <span class="token punctuation">(</span>_factory<span class="token punctuation">.</span><span class="token function">find</span><span class="token punctuation">(</span>type<span class="token punctuation">)</span> <span class="token operator">==</span> _factory<span class="token punctuation">.</span><span class="token function">end</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
    <span class="token keyword">throw</span> <span class="token function">RayTracerException</span><span class="token punctuation">(</span><span class="token string">"Component "</span> <span class="token operator">+</span> type <span class="token operator">+</span> <span class="token string">" not found"</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
tmp <span class="token operator">=</span> _factory<span class="token punctuation">.</span><span class="token function">find</span><span class="token punctuation">(</span>type<span class="token punctuation">)</span><span class="token operator">-></span><span class="token function">second</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><p>On a notre variable <code v-pre>type</code> comme <code v-pre>std::string</code> et qui contient le nom de notre primitive. Si le nom de la primitive dans <code v-pre>type</code> n'est pas dans la factory, alors on lève une exception. Sinon, dans le cas contraire, on appelle la fonction associée au nom de la primitive.</p>
<div class="custom-container tip"><p class="custom-container-title">TIP</p>
<p>Pour rajouter facilement des primitives, des matériaux, des textures ou des boxes, c'est très simple, il suffit de rajouter une ligne dans la factory de votre choix ainsi qu'une fonction pour son implémentation et le tour est joué !</p>
</div>
<h2 id="🧭-le-makefile" tabindex="-1"><a class="header-anchor" href="#🧭-le-makefile" aria-hidden="true">#</a> 🧭 Le Makefile</h2>
<div class="custom-container warning"><p class="custom-container-title"><ins> Qu'est ce que le Makefile ? </ins></p>
<p>Le Makefile est un fichier qui permet de compiler un programme. Il contient des règles qui permettent de compiler un programme.</p>
</div>
<div class="language-Makefile line-numbers-mode" data-ext="Makefile"><pre v-pre class="language-Makefile"><code>##
## EPITECH PROJECT, 2023
## B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
## File description:
## Makefile
##

CXX			=	g++ -std=c++17 \
				-I./sources/abstract \
				-I./sources/interfaces \
				-I./sources/material \
				-I./sources/math \
				-I./sources/primitives \
				-I./sources/utils \

CXXFLAGS	=	-Wall -Wextra -floop-parallelize-all -g3

LDFLAGS		=	-lconfig++

SRC			=	$(shell find -name &quot;*.cpp&quot;)

OBJ			=	$(SRC:.cpp=.o)

BIN			=	raytracer

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) -o $(BIN) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(BIN)
	$(RM) *.ppm

re: fclean all
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><p>Une fois que vous avez créé votre <code v-pre>Makefile</code>, vous pouvez maintenant compiler votre librairie.</p>
<div class="language-bash line-numbers-mode" data-ext="sh"><pre v-pre class="language-bash"><code>$ <span class="token function">make</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div></div></div><p>Il existe également d'autres commandes comme :</p>
<div class="language-bash line-numbers-mode" data-ext="sh"><pre v-pre class="language-bash"><code>$ <span class="token function">make</span> re
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div></div></div><p>Qui vous permet de recompiler la totalité du projet, mais encore :</p>
<div class="language-bash line-numbers-mode" data-ext="sh"><pre v-pre class="language-bash"><code>$ <span class="token function">make</span> fclean
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div></div></div><p>Qui elle vous permet de nettoyer l'ensemble du projet.</p>
<p>Une fois <code v-pre>make</code> utilisé vous pouvez maitenant lancer votre programme avec une scène afin de voir le résultat.</p>
</div></template>


