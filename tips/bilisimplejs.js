// ==UserScript==
// 如何写一个脚本 https://segmentfault.com/a/1190000023278206
// @name         b站界面简化
// @namespace    http://tampermonkey.net/
// @version      1.0
// @description  try to take over the world!
// @author       kongla
// @match        http://*/*
// @icon         data:image/gif;base64,R0lGODlhAQABAAAAACH5BAEKAAEALAAAAAABAAEAAAICTAEAOw==
// @grant        none
// ==/UserScript==

(function() {
    'use strict';
    // ==b站搜索界面化==

(() => {
    console.log("开启了b站改成搜索界面的脚本");
    /**
     * 让一个html标签取消显示
     * @param className 字符串，如 ".bili-feed4-layout"
     */
    let close = className => {
        let node = document.querySelector(className);
        if (node !== null) {
            node.style.display = "none";
        }
    }
    close(".bili-feed4-layout");
    close(".header-channel-fixed");
    close(".bili-header__channel");
    close(".bili-header__banner");
    //document.querySelector("body").style.backgroundColor = "black";
    document.querySelector(".bili-header__bar").style.backgroundColor = "black";
    document.querySelector(".bili-header__bar").style.justifyContent = "center";
    close(".trendings-double");
    close(".trending");
    close(".palette-button-wrap");
    close(".left-entry");
    let c = document.querySelector(".center-search-container");
    c.style.position = "absolute";
    c.style.top = "200px";
    c.style.width = "500px";
    c.style.left = "50%";
    c.style.marginLeft = "-250px";
    let title = document.createElement("h1");
    title.innerText = "搜索你想要搜的";
    //title.style.color = "white";
    title.style.textAlign = "center";
    c.appendChild(document.createElement("br"));
    c.appendChild(title);
})();
})();
