package com.localgift.giftlist.franchisee;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.apache.ibatis.session.SqlSession;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

import com.localgift.giftlist.store.StoreVO;

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
	
	public List<FranchiseeVO> searchFranchiseeList(String column, String keyword) {
		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put("column", column);
		searchMap.put("keyword", "%" + keyword + "%");
		return sqlSession.selectList("Franchisee.searchFranchiseeList", searchMap);
	}
	
	public List<FranchiseeVO> lookoutFranchiseeList(String latitude, String longitude) {
		Map<String, Object> lookoutMap = new HashMap<String, Object>();
		lookoutMap.put("latitude", Float.parseFloat(latitude));
		lookoutMap.put("longitude", Float.parseFloat(longitude));
		return sqlSession.selectList("Franchisee.lookoutFranchiseeList", lookoutMap);
	}
}
