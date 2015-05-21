$(document).ready(function(){
    
    checkCookie();

    function checkCookie() {
        var to_do;
        var i = 0;
        while (i >= 0)
        {
            to_do = getCookie('to_do' + i);
            if (to_do != null && to_do != "")
                create_to_do('to_do' + i, to_do);
            else
                break ;
            i++;
        }
    }

    function setCookie(sName, sValue) {
        var today = new Date(), expires = new Date();
        expires.setTime(today.getTime() + (365*24*60*60*1000));
        document.cookie = sName + "=" + encodeURIComponent(sValue) + ";expires=" + expires.toGMTString();
    }

    function unsetCookie(sName, sValue) {
        document.cookie = sName + "=" + encodeURIComponent(sValue) + ";expires=Thu, 01 Jan 1970 00:00:01 GMT";
    }

    function getCookie(sName) {
        var cookContent = document.cookie, cookEnd, i, j;
        var sName = sName + "=";
 
        for (i=0, c=cookContent.length; i<c; i++) {
                j = i + sName.length;
                if (cookContent.substring(i, j) == sName) {
                        cookEnd = cookContent.indexOf(";", j);
                        if (cookEnd == -1) {
                                cookEnd = cookContent.length;
                        }
                        return decodeURIComponent(cookContent.substring(j, cookEnd));
                }
        }       
        return null;
    }

    $("#sub").click(function(){
        var to_do = prompt ("Enter a new to do");
        var list = $(".to_do");
        var i = 0;
        if (list)
            i = list.length;
        if (to_do != null) {
            create_to_do('to_do' + i, to_do, "new");
            setCookie('to_do' + i, to_do);
        }
        i++;
    });

    function create_to_do(id, value, age) {
        var list = $('#ft_list');
        var el = $(id);

        if (value != "" && value != null)
        {
            new_div = "<div id='"+id+"' class='to_do'>"+value+"</div>";
            list.prepend(new_div);
            el.text = value;
            if (age == "new")
                setCookie(id, value);
        }
    }

    $(document).on('click', "div.to_do", function() {
        var r = confirm("Sur ?");
        if (r == true)
        {
            unsetCookie($(this).attr('id'), $(this).text());
            $(this).remove();
        }
    });
});
