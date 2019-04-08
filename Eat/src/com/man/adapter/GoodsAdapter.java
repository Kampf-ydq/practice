package com.man.adapter;

import java.util.List;

import com.example.eat.R;
import com.man.dao.GoodsDao;
import com.man.entity.Goods;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

public class GoodsAdapter extends ArrayAdapter<Goods> {
	private int resourceId;
	
	public GoodsAdapter(Context context, int textViewResourceId,
			List<Goods> objects) {
		super(context, textViewResourceId, objects);
		resourceId = textViewResourceId;
	}

	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		Goods goods = getItem(position);//��ȡ��ǰ���Goodsʵ��
		View view;
		ViewHolder viewHolder;
		
		//����convertView���沼�֣��������Ч��
		if (convertView == null) {
			view = LayoutInflater.from(getContext()).inflate(resourceId, parent, false);
			
			//��ʼ���ؼ�
			viewHolder = new ViewHolder();
			viewHolder.goodsImage = (ImageView) view.findViewById(R.id.goods_image);
			viewHolder.goodsName = (TextView) view.findViewById(R.id.goods_name);
			viewHolder.price = (TextView)view.findViewById(R.id.goods_price);
			viewHolder.storeNum = (TextView)view.findViewById(R.id.store_number);
			
			//��viewHolder�洢��view��
			view.setTag(viewHolder);
		}else {
			view = convertView;//����
			viewHolder = (ViewHolder)view.getTag();//���»�ȡViewHolder
		}
		
		//���������Ϣ
		GoodsDao goodsDao = new GoodsDao(getContext());
		viewHolder.goodsImage.setImageBitmap(goodsDao.chageToBitmap(goods.getGoodsImage()));//��λͼ��ʾΪͼƬ
		viewHolder.goodsName.setText(goods.getGoodsName());
		
		//������String.valueOf������doubleתΪString
		viewHolder.price.setText(String.valueOf(goods.getPrice()));
		viewHolder.storeNum.setText(String.valueOf(goods.getStoreNum()));
		return view;
	}
	
	//��ʵ���ؼ����л���
		class ViewHolder{
			
			ImageView goodsImage;
			
			TextView goodsName;
			
			TextView price;
			
			TextView storeNum;
		}



}
