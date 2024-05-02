package com.localgift.giftlist.store;

import java.util.List;

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
}
