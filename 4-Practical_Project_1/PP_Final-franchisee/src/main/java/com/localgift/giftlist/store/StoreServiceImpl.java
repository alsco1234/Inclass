package com.localgift.giftlist.store;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class StoreServiceImpl implements StoreService{
	
	@Autowired
	StoreDAO storeDAO;
	
	@Override
	public int insertStore(StoreVO vo) {
		return storeDAO.insertStore(vo);
	}
	
	@Override
	public StoreVO getStore(int seq) {
		return storeDAO.getStore(seq);
	}
	
	@Override
	public List<StoreVO> getStoreList() {
		return storeDAO.getStoreList();
	}

	@Override
	public int updateStore(StoreVO vo) {
		return storeDAO.updateStore(vo);
	}
	
	@Override
	public int deleteStore(int id) {
		return storeDAO.deleteStore(id);
	}
}
