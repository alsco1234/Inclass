package com.localgift.user;

import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@Controller
@RequestMapping(value="/login")
public class LoginController {
	@Autowired
	UserServiceImpl service;
	
	@RequestMapping(value="/login", method=RequestMethod.GET)
	public String login() {
		return "login";
	}
	
	@RequestMapping(value="/loginOk", method=RequestMethod.POST)
	public String loginCheck(HttpSession session, UserVO vo) {
		if(session.getAttribute("login") != null) {
			session.removeAttribute("login");
		}
		
		UserVO loginVO = service.getUser(vo);
		if(loginVO != null) {
			System.out.println("로그인 성공!");
			session.setAttribute("login", loginVO);
			return "redirect:/store/list";
		}
		System.out.println("로그인 실패..");
		return "redirect:login";
	}
	
	@RequestMapping(value="/logout")
	public String logout(HttpSession session) {
		session.invalidate();
		return "redirect:login";
	}
}