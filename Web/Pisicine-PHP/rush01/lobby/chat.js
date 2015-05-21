

function submitChat(uname)
	{
		if (form1.msg.value == '')
			return ;
		var msg = form1.msg.value;
		form1.msg.value = "";
		var xmlhttp = new XMLHttpRequest();
		xmlhttp.onreadystatechange = function () 
		{
			if (xmlhttp.readyState == 4 && xmlhttp.status == 200)
				document.getElementById('chatlogs').innerHTML = xmlhttp.responseText;
		}
			xmlhttp.open('GET', 'lobby/insert.php?uname='+uname+'&msg='+msg, true);
			xmlhttp.send();
		}
		$(document).ready(function(e)
		{
			$.ajaxSetup({cache:false});
			setInterval(function() { $('#chatlogs').load('lobby/logs.php')}, 2000);
		})
		setInterval(function() 
			{
				var elem = $("#chatlogs");
				var maxScrollTop = elem[0].scrollHeight - elem.outerHeight();
				document.getElementById('chatlogs').scrollTop = maxScrollTop;
			}, 2000);