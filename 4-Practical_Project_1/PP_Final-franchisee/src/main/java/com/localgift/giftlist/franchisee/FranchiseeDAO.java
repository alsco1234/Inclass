package com.localgift.giftlist.franchisee;

import java.util.List;

import org.apache.ibatis.session.SqlSession;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

@Repository
public class FranchiseeDAO {
	
	@Autowired
	SqlSession sqlSession;
	
	public int insertFranchisee(FranchiseeVO vo) {
		return sqlSession.insert("Franchisee.insertFranchisee", vo);
	}
	
	public FranchiseeVO getFranchisee(int seq) {
		return sqlSession.selectOne("Franchisee.getFranchisee", seq);
	}
	
	public List<FranchiseeVO> getFranchiseeList() {
		return sqlSession.selectList("Franchisee.getFranchiseeList");
	}
	
	public int updateFranchisee(FranchiseeVO vo) {
		return sqlSession.update("Franchisee.updateFranchisee", vo);
	}
	
	public int deleteFranchisee(int seq) {
		return sqlSession.delete("Franchisee.deleteFranchisee", seq);
	}
}
