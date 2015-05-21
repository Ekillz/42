function setCookie(sName, sValue) {
    var today = new Date(), expires = new Date();
    expires.setTime(today.getTime() + (365*24*60*60*1000));
    document.cookie = sName + "=" + encodeURIComponent(sValue) + ";expires=" + expires.toGMTString();
}

function getCookie(sName) {
    var oRegex = new RegExp("(?:; )?" + sName + "=([^;]*);?");

    if (oRegex.test(document.cookie)) {
            return decodeURIComponent(RegExp["$1"]);
    } else {
            return null;
    }
}

function checkCookie() {

    var el = getCookie("list");
    var list = document.getElementsByClassName('to_do');
    if (el) {
        document.body.innerHTML = el;
        for (var i = 0; i < list.length; i++) {
            var to_do =  document.getElementById('to_do' + i);
            to_do.onclick = function() {
                var r = confirm("Sur ?");
                if (r == true) {
                    to_do.parentNode.removeChild(to_do);
                    var markup = document.body.innerHTML;
                    setCookie("list", markup);
                    checkCookie();
                }
            }
        }
    } 
}

function new_to_do( to_do ) {
    var to_do = prompt ("Enter a new to do");
    var list = document.getElementsByClassName('to_do');
    var i = 0;
    if (list)
        i = list.length;
	if (to_do != "" && to_do != null) {
        var new_div = document.createElement('div');
        var list = document.getElementById('ft_list');
        var el = document.getElementById('to_do' + i);

		new_div.className = "to_do";
		new_div.id = 'to_do' + i;
        new_div.onclick = "delete(this.id)";
		list.insertBefore(new_div, list.childNodes[0]);
        el = document.getElementById('to_do' + i);
		el.innerHTML = to_do;
		el.onclick = function() {
            var r = confirm("Sur ?");
            if (r == true) {
                el.parentNode.removeChild(el);
                var markup = document.body.innerHTML;
                setCookie("list", markup);
            }
		}
        var markup = document.body.innerHTML;
        setCookie("list", markup);
	}
	i++;
}
