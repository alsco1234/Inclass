<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>포항사랑상품권 사이트 로그인</title>
</head>
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css"
        integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
<link href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" rel="stylesheet" />
<!-- ref: https://mdbootstrap.com/docs/standard/extended/login/#:~:text=EDIT%20IN%20SANDBOX-,Login%20form%20%236,-LOGIN -->
<style>
	.gradient-custom {
		/* fallback for old browsers */
		background: #6a11cb;
		
		/* Chrome 10-25, Safari 5.1-6 */
		background: -webkit-linear-gradient(to right, rgba(106, 17, 203, 1), rgba(37, 117, 252, 1));
		
		/* W3C, IE 10+/ Edge, Firefox 16+, Chrome 26+, Opera 12+, Safari 7+ */
		background: linear-gradient(to right, rgba(106, 17, 203, 1), rgba(37, 117, 252, 1))
	}
</style>
<body>
	<section class="vh-100 gradient-custom">
	  <div class="container py-5 h-100">
	    <div class="row d-flex justify-content-center align-items-center h-100">
	      <div class="col-12 col-md-8 col-lg-6 col-xl-5">
	        <div class="card bg-dark text-white" style="border-radius: 1rem;">
	          <div class="card-body p-5 text-center">
	            <form method="post" action="loginOk" class="mb-md-5 mt-md-4 pb-5">
	              <h2 class="fw-bold mb-2 text-uppercase">포항사랑상품권 사이트 로그인</h2>
	              <p class="text-white-50 mb-5">아이디와 비밀번호를 입력하세요!</p>
	              <div class="form-outline form-white mb-4">
	                <input type="text" id="userid" name="userid" class="form-control form-control-lg" placeholder="아이디" />
	              </div>
	              <div class="form-outline form-white mb-4">
	                <input type="password" id="password" name="password" class="form-control form-control-lg" placeholder="비밀번호" />
	              </div>
	              
	              <button class="btn btn-outline-light btn-lg px-5" type="submit">로그인</button>
	            </form>
	            <div>
	              <p class="mb-0">
	              	계정이 없나요?
	              	<a href="../guest/store/list" class="text-white-50 fw-bold">
	              	  <u><i class="fa fa-user-circle px-1"></i></u>게스트 로그인
	              	</a>
             	  </p>
	            </div>
	
	          </div>
	        </div>
	      </div>
	    </div>
	  </div>
	</section>
</body>
</html>