<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>판매점 정보</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css"
        integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <link href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" rel="stylesheet" />
    <script src="https://code.jquery.com/jquery-3.6.0.min.js" integrity="sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4=" crossorigin="anonymous"></script>
    <!-- ref: https://www.bootdey.com/snippets/view/Event-Schedule-list -->
    <style>
        .event-store-area .tab-area .nav-tabs {
            border-bottom: inherit;
        }

        .event-store-area .tab-area .nav {
            border-bottom: inherit;
            display: -webkit-box;
            display: -ms-flexbox;
            display: flex;
            -webkit-box-orient: vertical;
            -webkit-box-direction: normal;
            -ms-flex-direction: column;
            flex-direction: column;
            margin-top: 80px;
        }

        .event-store-area .tab-area .nav-item {
            margin-bottom: 75px;
        }

        .event-store-area .tab-area .nav-item .nav-link {
            text-align: center;
            font-size: 22px;
            color: #333;
            font-weight: 600;
            border-radius: inherit;
            border: inherit;
            padding: 0px;
            text-transform: capitalize !important;
        }

        .event-store-area .tab-area .nav-item .nav-link.active {
            color: #4125dd;
            background-color: transparent;
        }

        .event-store-area .tab-area .tab-content .table {
            margin-bottom: 0;
            width: 80%;
        }

        .event-store-area .tab-area .tab-content .table thead td,
        .event-store-area .tab-area .tab-content .table thead th {
            border-bottom-width: 1px;
            font-size: 20px;
            font-weight: 600;
            color: #252525;
        }

        .event-store-area .tab-area .tab-content .table td,
        .event-store-area .tab-area .tab-content .table th {
            border: 1px solid #b7b7b7;
            padding-left: 30px;
        }

        .event-store-area .tab-area .tab-content .table tbody th .heading,
        .event-store-area .tab-area .tab-content .table tbody td .heading {
            font-size: 16px;
            text-transform: capitalize;
            margin-bottom: 16px;
            font-weight: 500;
            color: #252525;
            margin-bottom: 6px;
        }

        .event-store-area .tab-area .tab-content .table tbody th span,
        .event-store-area .tab-area .tab-content .table tbody td span {
            color: #152733;
            font-size: 18px;
            text-transform: uppercase;
            margin-bottom: 6px;
            display: block;
        }

        .event-store-area .tab-area .tab-content .table tbody th span.date,
        .event-store-area .tab-area .tab-content .table tbody td span.date {
            color: #656565;
            font-size: 14px;
            font-weight: 500;
            margin-top: 15px;
        }

        .event-store-area .tab-area .tab-content .table tbody th p {
            font-size: 14px;
            margin: 0;
            font-weight: normal;
        }

        .event-store-area-two .primary-btn {
            margin-top: 40px;
        }

        .event-store-area-two .tab-content .table {
            -webkit-box-shadow: 0 1px 30px rgba(0, 0, 0, 0.1);
            box-shadow: 0 1px 30px rgba(0, 0, 0, 0.1);
            margin-bottom: 0;
        }
        
        /* .inner-box .btn-layout .primary-btn .btn-primary {
            background-color: #152733;
            border: 1px solid #b7b7b7;
            color: #fff;
            font-size: 16px;
        } */

        .event-store-area-two .tab-content .table thead {
            background-color: #152733;
            color: #fff;
            font-size: 20px;
        }

        .event-store-area-two .tab-content .table thead tr th {
            padding: 20px;
            border: 0;
        }

        .event-store-area-two .tab-content .table tbody {
            background: #fff;
        }

        .event-store-area-two .tab-content .table tbody tr.inner-box {
            border-bottom: 1px solid #dee2e6;
        }

        .event-store-area-two .tab-content .table tbody tr th {
            border: 0;
            padding: 30px 20px;
            vertical-align: middle;
        }

        .event-store-area-two .tab-content .table tbody tr th .event-date {
            color: #252525;
            text-align: center;
        }

        .event-store-area-two .tab-content .table tbody tr th .event-date span {
            font-size: 50px;
            line-height: 50px;
            font-weight: normal;
        }

        .event-store-area-two .tab-content .table tbody tr td {
            padding: 30px 20px;
            vertical-align: middle;
        }
        
        .event-store-area-two .tab-content .table tbody tr td.btn-layout {
            padding: 30px 5	px;
            vertical-align: middle;
        }

        .event-store-area-two .tab-content .table tbody tr td .r-no span {
            color: #252525;
        }

        .event-store-area-two .tab-content .table tbody tr td .event-wrap h3 p {
            font-size: 22px;
            line-height: 20px;
            color: #cf057c;
            -webkit-transition: all 0.4s;
            -o-transition: all 0.4s;
            transition: all 0.4s;
        }

        .event-store-area-two .tab-content .table tbody tr td .event-wrap h3 p:hover {
            color: #4125dd;
        }

        .event-store-area-two .tab-content .table tbody tr td .event-wrap .meta p {
            color: #252525;
            font-size: 16px;
            line-height: 18px;
            margin-left: 10px;
            -webkit-transition: all 0.4s;
            -o-transition: all 0.4s;
            transition: all 0.4s;
        }

        .event-store-area-two .tab-content .table tbody tr td .event-wrap .meta p:before {
            content: " ";
            padding-right: 5px;
        }

        .event-store-area-two .tab-content .table tbody tr td .primary-btn {
            margin-top: 0;
            text-align: center;
        }

        .event-store-area-two .tab-content .table tbody tr td .event-img img {
            width: 100px;
            height: 100px;
            border-radius: 8px;
        }
        
        .event-store-area-two nav .container .collapse .input-group div.input-group-prepend .rounded-0 {
        	border-radius: 5px 0 0 5px!important;
        }
        
        .event-store-area-two nav .container .collapse .input-group div.input-group-append .rounded-0 {
        	border-radius: 0 5px 5px 0!important;
        }
        
        button.gotoDownBtn {
        	position: fixed;
        	background-color: #fff;
        	border: 0;
        	right: 5%;
        	bottom: 5%;
        	width: 50px;
        	height: 50px;
       	    box-shadow: 5px 5px 5px 0px rgba(8, 8, 8, 0.3);
        }
        
    </style>
</head>

<body>
    <div class="event-store-area-two bg-color">
        <!-- <div class="container"> -->
        <div>
          <nav class="navbar navbar-expand-lg navbar-dark bg-dark" aria-label="Eighth navbar example">
		    <div class="container">
		      <h2 class="navbar-brand  mb-lg-0">판매점 정보</h2>
		      <div class="collapse navbar-collapse" id="navbarsExample07">
		        <ul class="navbar-nav me-auto mb-2 mb-lg-0">
		          <li class="nav-item">
		            <a class="nav-link active" aria-current="page" href="#">홈</a>
		          </li>
		          <li class="nav-item">
		            <a class="nav-link" href="../store/list">판매점</a>
		          </li>
		          <li class="nav-item">
		            <a class="nav-link" href="../franchisee/list">가맹점</a>
		          </li>
		          <li class="nav-item">
		            <a class="nav-link" href="../login/logout">로그아웃</a>
		          </li>
		        </ul>
		        <form action="list" class="input-group w-50">
	        	  <div class="input-group-prepend">
				    <select class="form-select rounded-0" id="searchSelect" name="column" onchange="changeInputPlaceholder()">
				      <option value="belong" selected>금융기관명</option>
				      <option value="name">판매 및 환전처명</option>
				      <option value="address">주소</option>
				      <option value="position">내 위치</option>
				    </select>
				  </div>
		          <input class="form-control" id="searchText" name="keyword" type="text" placeholder="금융기관명(으)로 검색해보세요" aria-label="Search" required>
		          <div class="input-group-append">
				    <button class="btn btn-outline-secondary rounded-0" type="submit">검색</button>
				  </div>
	          	</form>
		      </div>
		    </div>
		  </nav>
            <div class="row">
                <div class="col-lg-12">
                    <div class="tab-content" id="myTabContent">
                        <div class="tab-pane fade active show" id="home" role="tabpanel">
                            <div class="table-responsive">
                                <table class="table">
                                    <thead>
                                        <tr>
                                            <th class="text-center" scope="col">Id</th>
                                            <th class="text-center" scope="col">금융기관</th>
                                            <th class="text-center" scope="col">금융기관</th>
                                            <th class="text-center" scope="col">수정일</th>
                                            <th class="text-center" scope="col" colspan="2">수정 및 삭제</th>
                                        </tr>
                                    </thead>
                                    <tbody>
                                        <c:forEach items="${list}" var="u">
                                            <tr class="inner-box">
                                                <th scope="row">
                                                    <div class="event-date">
                                                        <span>${u.getSeq()}</span>
                                                        <p>판매점</p>
                                                    </div>
                                                </th>
                                                <td>
                                                    <div class="event-img">
                                                        <img src="https://www.freeiconspng.com/uploads/no-image-icon-6.png" width="100%" alt="Icon No Download" />
                                                    </div>
                                                </td>
                                                <td>
                                                    <div class="event-wrap px-3">
                                                        <h3><p>${u.getBelong()}</p></h3>
                                                        <div class="meta">
                                                            <p>${u.getName()}</p>
                                                            <p>${u.getAddress()}</p>
                                                            <p>${u.getLatitude()}, ${u.getLongitude()}</p>
                                                        </div>
                                                    </div>
                                                </td>
                                                <td>
                                                    <div class="r-no"><span>${u.toRegdateString()}</span></div>
                                                </td>
                                                <td class="btn-layout">
                                                    <div class="primary-btn">
                                                        <a class="btn btn-dark" href="editpost/${u.getSeq()}">수정하기</a>
                                                    </div>
                                                </td>
                                                <td class="btn-layout">
                                                    <div class="primary-btn">
                                                        <a class="btn btn-dark"
                                                            href="javascript:delete_ok('${u.getSeq()}')">삭제하기</a>
                                                    </div>
                                                </td>
                                            </tr>
                                        </c:forEach>
                                    </tbody>
                                </table>
                            </div>
                        </div>
                        <div class="primary-btn text-center mb-3">
                            <a href="add" class="btn btn-dark">새 금융기관 등록하기</a>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <footer>
      <ul class="nav justify-content-center border-bottom pb-3 mt-3 mb-3">
        <li class="nav-item"><a href="#" class="nav-link px-2 text-muted">Home</a></li>
        <li class="nav-item"><a href="javascript:gotoTop()" class="nav-link px-2 text-muted">Header</a></li>
        <li class="nav-item"><a href="https://github.com/alsco1234/PP_Final" class="nav-link px-2 text-muted">Github</a></li>
        <li class="nav-item"><a href="../login/logout" class="nav-link px-2 text-muted">Logout</a></li>
      </ul>
      <p class="text-center text-muted">© 2021 실전프로젝트1 기말 과제</p>
    </footer>
    <button class="rounded-circle gotoDownBtn" onclick="gotoBottom()">
    	<i class="fa fa-chevron-down fa-2x"></i>
    </button>
    <script>
        function delete_ok(id) {
            var a = confirm("정말로 삭제하겠습니까?");
            if (a) location.href = 'delete/' + id;
        }
        
        function changeInputPlaceholder() {
        	var selectedOption = $('#searchSelect option:checked').text();
        	if(selectedOption !== '내 위치') {
        		$('#searchText').attr('placeholder', selectedOption + '(으)로 검색해보세요');
        		$('#searchText').removeAttr('pattern');
        		$('#searchText').removeAttr('title');
        	}
        	else {
        		$('#searchText').attr('placeholder', '현재 위치(위도, 경도)로 검색해보세요');
        		$('#searchText').attr('pattern', '^[0-9]+([\.][0-9]+)?, [0-9]+([\.][0-9]+)?$');
        		$('#searchText').attr('title', '이 입력란을 작성하세요.\n입력 방식 : 정수 혹은 실수 2개를 ", "로 구분');
        	}
        }
        
        function gotoTop() {
			document.body.scrollTop = 0; // For Safari
			document.documentElement.scrollTop = 0; // For Chrome, Firefox, IE and Opera
        }
        
        function gotoBottom() {
        	$("html, body").animate({ scrollTop: $("html, body").height() }, 300);
        }
    </script>
</body>
</html>