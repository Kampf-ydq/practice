package com.man.dao;

import java.io.ByteArrayOutputStream;
import java.util.ArrayList;
import java.util.List;

import android.R.integer;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.BitmapDrawable;
import db.helper.MySQLiteHelper;
import com.man.entity.Goods;

public class GoodsDao {
	
	MySQLiteHelper helper;
	
	public GoodsDao(Context context){
		helper = new MySQLiteHelper(context);
	}
	
	public void insert(Goods goods){
		SQLiteDatabase db = helper.getWritableDatabase();
		db.execSQL("insert into t_goods values(null,?,?,?,?)", new Object[]{
				goods.getGoodsName(),goods.getGoodsImage(),goods.getPrice(),goods.getStoreNum()
		});
		db.close();
	}
	
	public void delete(String id){
		SQLiteDatabase db = helper.getWritableDatabase();
		db.execSQL("delete from t_goods where goodsId=?", new Object[]{id});
		db.close();
	}
	public void update(int storeNum,String id){
		SQLiteDatabase db = helper.getWritableDatabase();
		db.execSQL("update t_goods set storeNum=? where goodsId=?",
				new Object[]{storeNum,id});
		db.close();
	}
	public Goods find(String id){
		SQLiteDatabase db = helper.getReadableDatabase();
		Cursor cursor = db.rawQuery("select * from t_goods where goodsId=?", new String[]{id});
	
		boolean result = cursor.moveToNext();
		
		Goods goods = null;
		if (result) {
			int goodsId = cursor.getInt(cursor.getColumnIndex("goodsId"));
			String goodsName = cursor.getString(cursor.getColumnIndex("goodsName"));
			byte[] goodsImage = cursor.getBlob(cursor.getColumnIndex("goodsImage"));
			double price = cursor.getDouble(cursor.getColumnIndex("price"));
			int storeNum = cursor.getInt(cursor.getColumnIndex("storeNum"));
			
			goods = new Goods(String.valueOf(goodsId), goodsName, goodsImage, price, storeNum);
		} 
		db.close();
		return goods;
	}
	

	//����t_goods��������м�¼
	public List<Goods> getAll(){
		List<Goods> goodsList = new ArrayList<Goods>();
		SQLiteDatabase db = helper.getReadableDatabase();
		
		Cursor cursor = db.rawQuery("select * from t_goods", null);
		while (cursor.moveToNext()) {
			int goodsId = cursor.getInt(cursor.getColumnIndex("goodsId"));
			String goodsName = cursor.getString(cursor.getColumnIndex("goodsName"));
			byte[] goodsImage = cursor.getBlob(cursor.getColumnIndex("goodsImage"));
			double price = cursor.getDouble(cursor.getColumnIndex("price"));
			int storeNum = cursor.getInt(cursor.getColumnIndex("storeNum"));
			
			Goods goods = new Goods(String.valueOf(goodsId), goodsName, goodsImage, price, storeNum);
			goodsList.add(goods);
		}
		db.close();
		return goodsList;
	}
	
	//��ͼƬתΪbyte[]
	public byte[] bitmapToBytes(Context context,int id){
		 ByteArrayOutputStream baos = new ByteArrayOutputStream();
	     Bitmap bitmap = ((BitmapDrawable) context.getResources().getDrawable(id)).getBitmap();
	     bitmap.compress(Bitmap.CompressFormat.PNG, 100, baos);
	     return baos.toByteArray();
	}
	
	//��Byte[]תΪBitmap
	public Bitmap chageToBitmap(byte[] in)
	{
		Bitmap bmpout = BitmapFactory.decodeByteArray(in, 0, in.length);
	    return bmpout;
	}
}
