package com.localgift.giftlist.franchisee;

import java.util.List;

public interface FranchiseeService {
	public int insertFranchisee(FranchiseeVO vo);
	public int deleteFranchisee(int id);
	public int updateFranchisee(FranchiseeVO vo);
	public FranchiseeVO getFranchisee(int seq);
	public List<FranchiseeVO> getFranchiseeList();
	public List<FranchiseeVO> searchFranchiseeList(String column, String keyword);
	public List<FranchiseeVO> lookoutFranchiseeList(String latitude, String longitude);
}