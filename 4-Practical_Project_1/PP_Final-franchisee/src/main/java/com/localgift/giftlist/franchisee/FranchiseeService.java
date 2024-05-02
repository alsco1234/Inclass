package com.localgift.giftlist.franchisee;

import java.util.List;

public interface FranchiseeService {
	public int insertFranchisee(FranchiseeVO vo);
	public int deleteFranchisee(int id);
	public int updateFranchisee(FranchiseeVO vo);
	public FranchiseeVO getFranchisee(int seq);
	public List<FranchiseeVO> getFranchiseeList();
}