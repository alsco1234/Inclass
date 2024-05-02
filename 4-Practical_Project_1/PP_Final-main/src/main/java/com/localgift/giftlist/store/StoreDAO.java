package com.localgift.giftlist.store;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.apache.ibatis.session.SqlSession;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

@Repository
public class StoreDAO {
	
	@Autowired
	SqlSession sqlSession;
	
	public int insertStore(StoreVO vo) {
		return sqlSession.insert("Store.insertStore", vo);
	}
	
	public StoreVO getStore(int seq) {
		return sqlSession.selectOne("Store.getStore", seq);
	}
	
	public List<StoreVO> getStoreList() {
		return sqlSession.selectList("Store.getStoreList");
	}
	
	public int updateStore(StoreVO vo) {
		return sqlSession.update("Store.updateStore", vo);
	}
	
	public int deleteStore(int seq) {
		return sqlSession.delete("Store.deleteStore", seq);
	}
	
	public List<StoreVO> searchStoreList(String column, String keyword) {
		Map<String, Object> searchMap = new HashMap<String, Object>();
		searchMap.put("column", column);
		searchMap.put("keyword", "%" + keyword + "%");
		return sqlSession.selectList("Store.searchStoreList", searchMap);
	}
	
	public List<StoreVO> lookoutStoreList(String latitude, String longitude) {
		Map<String, Object> lookoutMap = new HashMap<String, Object>();
		lookoutMap.put("latitude", Float.parseFloat(latitude));
		lookoutMap.put("longitude", Float.parseFloat(longitude));
		return sqlSession.selectList("Store.lookoutStoreList", lookoutMap);
	}
}
