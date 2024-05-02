package com.localgift.giftlist.franchisee;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class FranchiseeServiceImpl implements FranchiseeService{
	
	@Autowired
	FranchiseeDAO franchiseeDAO;
	
	@Override
	public int insertFranchisee(FranchiseeVO vo) {
		return franchiseeDAO.insertFranchisee(vo);
	}
	
	@Override
	public FranchiseeVO getFranchisee(int seq) {
		return franchiseeDAO.getFranchisee(seq);
	}
	
	@Override
	public List<FranchiseeVO> getFranchiseeList() {
		return franchiseeDAO.getFranchiseeList();
	}

	@Override
	public int updateFranchisee(FranchiseeVO vo) {
		return franchiseeDAO.updateFranchisee(vo);
	}
	
	@Override
	public int deleteFranchisee(int id) {
		return franchiseeDAO.deleteFranchisee(id);
	}

	@Override
	public List<FranchiseeVO> searchFranchiseeList(String column, String keyword) {
		return franchiseeDAO.searchFranchiseeList(column, keyword);
	}

	@Override
	public List<FranchiseeVO> lookoutFranchiseeList(String latitude, String longitude) {
		return franchiseeDAO.lookoutFranchiseeList(latitude, longitude);
	}
}
