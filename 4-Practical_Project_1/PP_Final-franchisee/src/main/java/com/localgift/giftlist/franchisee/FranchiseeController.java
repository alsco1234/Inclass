package com.localgift.giftlist.franchisee;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@Controller
public class FranchiseeController {
	
	@Autowired
	FranchiseeServiceImpl franchiseeService;
	
	@RequestMapping(value = "/franchisee/list", method = RequestMethod.GET)
	public String franchiseelist(Model model) {
		model.addAttribute("list", franchiseeService.getFranchiseeList());
		return "franchisee/posts";
	}
	
	@RequestMapping(value = "/franchisee/add", method = RequestMethod.GET)
	public String addPost() {
		return "franchisee/addform";
	}
	
	@RequestMapping(value = "/franchisee/addok", method = RequestMethod.POST)
	public String addPostOK(FranchiseeVO vo) {
		if(franchiseeService.insertFranchisee(vo) == 0)
			System.out.println("[오류] 데이터 추가 실패");
		else
			System.out.println("데이터 추가 성공!");
		return "redirect:/franchisee/list";
	}
	
	@RequestMapping(value = "/franchisee/editpost/{id}", method = RequestMethod.GET)
	public String editPost(@PathVariable("id") int id, Model model) {
		FranchiseeVO franchiseeVO = franchiseeService.getFranchisee(id);
		model.addAttribute("franchiseeVO", franchiseeVO);
		return "franchisee/editform";
	}
	
	@RequestMapping(value = "/franchisee/editok", method = RequestMethod.POST)
	public String editPostOK(FranchiseeVO vo) {
		if(franchiseeService.updateFranchisee(vo) == 0)
			System.out.println("[오류] 데이터 수정 실패");
		else
			System.out.println("데이터 수정 성공!");
		return "redirect:/franchisee/list";
	}
	
	@RequestMapping(value = "/franchisee/delete/{id}", method = RequestMethod.GET)
	public String deletePost(@PathVariable("id") int id) {
		franchiseeService.deleteFranchisee(id);
		return "redirect:/franchisee/list";
	}
	
}