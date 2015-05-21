$(document).ready(function(){

    $(function get_to_do() {
        $.get( "select.php", function( data ) {
            to_do_list = data.split(' ');
            for (var i = 0; i < to_do_list.length; i++)
            {
                if (i % 2 != 0)
                    create_to_do(to_do_list[i - 1], to_do_list[i], "old");
            }
        });
    })

    function save_to_do(id, val) {
        $.ajax({
            url : 'insert.php',
            type : 'GET',
            data : 'id=' + id + '&val=' + val,
            success: function (result) {
                console.log("save ok");
            }
        })
    }

    function delete_to_do(id, val){
        $.ajax({
            url : 'delete.php',
            type : 'GET',
            data : 'id=' + id + '&val=' + val,
            success: function (result) {
                console.log("delete ok");
            }
        })
    }

    $("#sub").click(function(){
        var to_do = prompt ("Enter a new to do");
        var list = $(".to_do");
        var i = 0;
        if (list)
            i = list.length;
        if (to_do != null) {
            create_to_do('to_do' + i, to_do, "new");
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
                save_to_do(id, value);
        }
    }

    $(document).on('click', "div.to_do", function() {
        var r = confirm("Sur ?");
        if (r == true)
        {
            $(this).remove();
            delete_to_do($(this).attr('id'), $(this).text());
        }
    });
});