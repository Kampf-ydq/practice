package com.man.dao;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import com.man.entity.User;

import db.helper.MySQLiteHelper;

public class UserDao {
	
	MySQLiteHelper helper;
	
	public UserDao(Context context) {
		helper = new MySQLiteHelper(context);
	}
	
	
	public void add(User user){
		//�õ��������ʵ����Ȼ��������ݿ�
		SQLiteDatabase db = helper.getWritableDatabase();
		db.execSQL("insert into t_user values(null,?,?,?,?,?,?,?,?)",new Object[]{user.getAccount(),user.getPassword(),
				"�򹤴�","С����","÷����","0000 8888 888","����ʡ������������ҵ��ѧ����У��",500});
		db.close();
	}
	public void delete(String id){
		SQLiteDatabase db = helper.getWritableDatabase();
		db.execSQL("delete from t_user where userId=?", new Object[]{id});
		db.close();
	}
	
	//�����ջ���ַ��Ϣ
	public void updateAddress(String name,String tel,String add,String account){
		SQLiteDatabase db = helper.getWritableDatabase();
		db.execSQL("update t_user set userName=?,telPhone=?,address=? where account=?", 
				new Object[]{name,tel,add,account});
		db.close();
	}
	
	//����ѧУ��Ϣ
	public void updateInfo(String school,String nick,String account){
		SQLiteDatabase db = helper.getWritableDatabase();
		db.execSQL("update t_user set school=?,nickName=? where account=?", 
				new Object[]{school,nick,account});
		db.close();
	}
	
	//����Moneyֵ
	public void updateMoney(double money,String account){
		SQLiteDatabase db = helper.getWritableDatabase();
		db.execSQL("update t_user set money=? where account=?", 
				new Object[]{money,account});
		db.close();
	}
	
	/*//�����ǳơ�ͷ�񡢵�¼����
	//����ѧУ��Ϣ
	public void updateInfor(String account,String nick,Byte[){
		SQLiteDatabase db = helper.getWritableDatabase();
		db.execSQL("update t_user set school=? where account=?", 
				new Object[]{school,account});
	}*/
	
	public User find(String acc){
		SQLiteDatabase db = helper.getReadableDatabase();//�����ݿ�
		
		//�α�,��ȡ����
		Cursor cursor = db.rawQuery("select * from t_user where account=?", new String[]{acc});
		
		boolean result = cursor.moveToNext();
		User user = null;
		if(result){
			
			int userId = cursor.getInt(cursor.getColumnIndex("userId"));
			String account = cursor.getString(cursor.getColumnIndex("account"));
			String password = cursor.getString(cursor.getColumnIndex("password"));
			String school = cursor.getString(cursor.getColumnIndex("school"));
			String nickName = cursor.getString(cursor.getColumnIndex("nickName"));
			String userName = cursor.getString(cursor.getColumnIndex("userName"));
			String telPhone = cursor.getString(cursor.getColumnIndex("telPhone"));
			String address = cursor.getString(cursor.getColumnIndex("address"));
			double money = cursor.getDouble(cursor.getColumnIndex("money"));
			
			user = new User(String.valueOf(userId), account, password, school, 
					nickName, userName, telPhone, address,money);
		}
		db.close();
		return user;
	}

}
