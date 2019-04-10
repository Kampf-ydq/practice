package com.man.test;

import android.test.AndroidTestCase;
import com.man.dao.UserDao;
import com.man.entity.User;

/*
 * ע��: д���Գ�����Ҫ��AndroidManifest�����instrumentation��uses-library
 */
public class TestUserDao extends AndroidTestCase {
	public void testAdd(){
		User user = new User(null, "160405222", "123456", "sut", "�޹���", "С��", "123456", "�򹤴�",500);
		//User user2 = new User();
		//user2.setAccount("198402");
		//user2.setPassword("45130");
		UserDao userDao = new UserDao(getContext());//getContext()����һ��ģ���context
		userDao.add(user);
		//userDao.add(user2);
	}
	
	public void testDelete(){
		UserDao userDao = new UserDao(getContext());
		userDao.delete("3");
	}

	public void testUpdate(){
		
		UserDao userDao = new UserDao(getContext());
		userDao.updateAddress("Jack", "18012450039", "������������", "160405221");
	}
	
	public void testFind(){
		UserDao userDao = new UserDao(getContext());
		User user = userDao.find("198402");
		
		System.out.println(user.toString());
	}
}
