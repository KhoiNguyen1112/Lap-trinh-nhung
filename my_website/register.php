	<html>
	<head>
		<title>Form dang ky thanh vien</title>
	</head>
	<body>
		<?php
		require_once("connection.php");
		if (isset($_POST["btn_submit"])) {
  			//lấy thông tin từ các form bằng phương thức POST
  			$username = $_POST["username"];
  			$password = $_POST["pass"];
  			//Kiểm tra điều kiện bắt buộc đối với các field không được bỏ trống
			  if ($username == "" || $password == "" ) {
				   echo "bạn vui lòng nhập đầy đủ thông tin";
  			}else{
  					// Kiểm tra tài khoản đã tồn tại chưa
  					$sql="select * from users where username='$username'";
					$kt=mysqli_query($conn, $sql);

					if(mysqli_num_rows($kt)  > 0){
						echo "Tài khoản đã tồn tại";
					}else{
						//thực hiện việc lưu trữ dữ liệu vào db
	    				$sql = "INSERT INTO users(
	    					username,
	    					password
	    					) VALUES (
	    					'$username',
	    					'$password'
	    					)";
					    // thực thi câu $sql với biến conn lấy từ file connection.php
   						mysqli_query($conn,$sql);
				   		echo "chúc mừng bạn đã đăng ký thành công";
					}
									    
					
			  }
	}
	?>
	<form action="register.php" method="post">
		<table>
			<tr>
				<td colspan="2">Form đăng ký</td>
			</tr>	
			<tr>
				<td>Username :</td>
				<td><input type="text" id="username" name="username"></td>
			</tr>
			<tr>
				<td>Password :</td>
				<td><input type="password" id="pass" name="pass"></td>
			</tr>
			<tr>
				<td colspan="2" align="center"><input type="submit" name="btn_submit" value="Dang ky"></td>
			</tr>

		</table>

	</form>
	<script>
	function goback() {
    		history.back(-1)
		}
	</script>
	<a href='javascript:goback()'>Quay lại trang trước</a>
	</body>
	</html>