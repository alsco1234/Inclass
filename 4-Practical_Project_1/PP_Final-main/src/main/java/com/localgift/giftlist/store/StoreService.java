package com.localgift.giftlist.store;

import java.util.List;

public interface StoreService {
	public int insertStore(StoreVO vo);
	public int deleteStore(int id);
	public int updateStore(StoreVO vo);
	public StoreVO getStore(int seq);
	public List<StoreVO> getStoreList();
	public List<StoreVO> searchStoreList(String column, String keyword);
	public List<StoreVO> lookoutStoreList(String latitude, String longitude);
}