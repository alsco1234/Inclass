package com.localgift.giftlist.store;

import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@Controller
public class StoreController {
	
	@Autowired
	StoreServiceImpl storeService;
	
	@RequestMapping(value = "/store/list", method = RequestMethod.GET)
	public String storelist(Model model, HttpServletRequest request) {
		String column = request.getParameter("column");
		String keyword = request.getParameter("keyword");
		if(column == null || keyword == null)
			model.addAttribute("list", storeService.getStoreList());
		else if(column.equals("position")) {
			String[] ll = keyword.split(", ");
			model.addAttribute("list", storeService.lookoutStoreList(ll[0], ll[1]));
		}
		else
			model.addAttribute("list", storeService.searchStoreList(column, keyword));
		return "store/posts";
	}

	@RequestMapping(value = "/store/add", method = RequestMethod.GET)
	public String addPost() {
		return "store/addform";
	}
	
	@RequestMapping(value = "/store/addok", method = RequestMethod.POST)
	public String addPostOK(StoreVO vo) {
		if(storeService.insertStore(vo) == 0)
			System.out.println("[오류] 데이터 추가 실패");
		else
			System.out.println("데이터 추가 성공!");
		return "redirect:/store/list";
	}
	
	@RequestMapping(value = "/store/editpost/{id}", method = RequestMethod.GET)
	public String editPost(@PathVariable("id") int id, Model model) {
		StoreVO storeVO = storeService.getStore(id);
		model.addAttribute("storeVO", storeVO);
		return "store/editform";
	}
	
	@RequestMapping(value = "/store/editok", method = RequestMethod.POST)
	public String editPostOK(StoreVO vo) {
		if(storeService.updateStore(vo) == 0)
			System.out.println("[오류] 데이터 수정 실패");
		else
			System.out.println("데이터 수정 성공!");
		return "redirect:/store/list";
	}
	
	@RequestMapping(value = "/store/delete/{id}", method = RequestMethod.GET)
	public String deletePost(@PathVariable("id") int id) {
		storeService.deleteStore(id);
		return "redirect:/store/list";
	}
	
	@RequestMapping(value = "/guest/store/list", method = RequestMethod.GET)
	public String guestStorelist(Model model, HttpServletRequest request) {
		String column = request.getParameter("column");
		String keyword = request.getParameter("keyword");
		if(column == null || keyword == null)
			model.addAttribute("list", storeService.getStoreList());
		else if(column.equals("position")) {
			String[] ll = keyword.split(", ");
			model.addAttribute("list", storeService.lookoutStoreList(ll[0], ll[1]));
		}
		else
			model.addAttribute("list", storeService.searchStoreList(column, keyword));
		return "guest/sposts";
	}
	
}